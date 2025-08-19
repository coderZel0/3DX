#ifndef ENGINE_H
#define ENGINE_H

#include "SDL3/SDL_render.h"
#include <functional>

namespace NEngine {

class Engine {
protected:
  SDL_Renderer *renderer;

public:
  Engine(SDL_Renderer *renderer) : renderer(renderer) {}
  void initialize(const std::function<void()> &init);
  void run(const std::function<void()> &game_loop_callback);
  void create_entity();
  void stop();
};
} // namespace NEngine

#endif
