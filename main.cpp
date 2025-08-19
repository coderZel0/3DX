#include "engine/engine.h"
#include "game/game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <flecs.h>

#define ASSERT_ENABLED 1
#include "engine/core/assert/assert.h"

int main(int argc, char *argv[]) {

  SDL_Window *window;
  SDL_Renderer *renderer;

  ASSERT(3 > 2);

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s",
                 SDL_GetError());
    return 1;
  }

  if (!SDL_CreateWindowAndRenderer("3dX", 800, 300, SDL_WINDOW_RESIZABLE,
                                   &window, &renderer)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't create window and renderer: %s", SDL_GetError());
    return 1;
  }

  flecs::world world;

  NEngine::Engine engine(renderer, world);

  Game game(renderer, world);

  engine.initialize(std::bind(&Game::init, &game));
  engine.run(std::bind(&Game::start, &game));

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
  return 0;
}
