#ifndef ENGINE_H
#define ENGINE_H

#include "SDL3/SDL_render.h"
#include <flecs.h>
#include <functional>

namespace NEngine {

class Engine {
  void register_ecs_components();
  void register_engine_systems();

protected:
  SDL_Renderer *renderer;
  flecs::world ecs_world;

public:
  Engine(SDL_Renderer *renderer, flecs::world &world)
      : renderer(renderer), ecs_world(world) {}
  void initialize(const std::function<void()> &init);
  void run(const std::function<void()> &game_loop_callback);
  void create_entity();
  void stop();
};
} // namespace NEngine

#endif
