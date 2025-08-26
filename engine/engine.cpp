#include "engine.h"
#include "ecs/components.h"
#include "ecs/systems/render.system.h"

using namespace NEngine;

void Engine::initialize(const std::function<void()> &init) {
  init(); // game initialization
  register_ecs_components();
  register_engine_systems();
}

void Engine::register_ecs_components() {
  ecs_world.component<Position>();
  ecs_world.component<Texture>();
  ecs_world.component<Rect>();
  ecs_world.set<RendererResource>({renderer});
}

void Engine::register_engine_systems() {
  ecs_world.system<Position, Texture, Rect>("RenderSystem")
      .each(SYSTEMS::RenderSystem::update);
}

void Engine::run(const std::function<void()> &game_loop) { game_loop(); }

void Engine::create_entity() {
  // Placeholder for creating an entity
}

void Engine::stop() {}
