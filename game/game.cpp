#include "game.h"
#include "engine/ecs/components.h"
#include "flecs.h"
#include "flecs/addons/flecs_c.h"
#include <iostream>

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
  auto e = ecsGameWorld.entity("Player");
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
