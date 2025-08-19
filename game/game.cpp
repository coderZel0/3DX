#include "game.h"
#include "ecs/components.h"

bool Game::running = false;

void Game::setRunning(bool run) { running = run; }

void Game::init() { setRunning(true); }

bool Game::isRunning() const { return running; }

void Game::start() {
  if (textureResourceManager == nullptr) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "TextureResourceManager is not initialized");
    return;
  }
  auto e = ecs_world.entity("Player");
  std::shared_ptr<SDL_Texture> playerTexture =
      textureResourceManager->loadResource("dirtSphere.png");

  e.add<Position>().set<Texture>({playerTexture.get()});
  // e.add<Texture>(playerTexture.get());
  // ecs_add(ecsGameWorld, e, Position);
  std::shared_ptr<SDL_Texture> texture =
      textureResourceManager->loadResource("T1.jpg");

  while (isRunning()) {
    SDL_PollEvent(&event);
    if (event.type == SDL_EVENT_QUIT) {
      break;
    }
    // SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture.get(), NULL, NULL);
    SDL_RenderPresent(renderer);
  }
}

void Game::stop() { setRunning(false); }

Game::~Game() {};
