#ifndef GAME_H
#define GAME_H

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_render.h"
#include "engine/resources/resource.h"
#include <flecs.h>

class Game {
  static bool running;
  SDL_Event event;
  SDL_Renderer *renderer;
  TextureResourceManager *textureResourceManager;
  flecs::world ecsGameWorld;

public:
  Game(SDL_Renderer *renderer)
      : renderer(renderer),
        textureResourceManager(new TextureResourceManager(renderer)) {}
  ~Game();

  void init();
  void start();
  void stop();
  void setRunning(bool run);

private:
  bool isRunning() const;
};

#endif
