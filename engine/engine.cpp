#include "engine.h"

using namespace NEngine;

void Engine::initialize(const std::function<void()> &init) { init(); }

void Engine::run(const std::function<void()> &game_loop) { game_loop(); }

void Engine::create_entity() {
  // Placeholder for creating an entity
}

void Engine::stop() {}
