#include "engine.h"
#include "ecs/components.h"

using namespace NEngine;

void Engine::initialize(const std::function<void()> &init) {
  init(); // game initialization
  register_ecs_components();
}

void Engine::register_ecs_components() {
  ecs_world.component<Position>();
  ecs_world.component<Texture>();
}

void Engine::initialize_engine_systems() {}

void Engine::run(const std::function<void()> &game_loop) { game_loop(); }

void Engine::create_entity() {
  // Placeholder for creating an entity
}

void Engine::stop() {}
