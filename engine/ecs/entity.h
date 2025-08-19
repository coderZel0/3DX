// engine/ecs/entity.h
#pragma once
#include <flecs.h>

namespace NEngine {

class Entity {
public:
  Entity() : m_entity(0), m_world(nullptr) {}
  Entity(ecs_world_t *world, ecs_entity_t entity)
      : m_entity(entity), m_world(world) {}

  // Add a component to the entity
  template <typename T> void add(const T &component) {
    ecs_set(m_world, m_entity, T, component);
  }

  // Get a component pointer
  template <typename T> T *get() {
    return ecs_get_mut(m_world, m_entity, T, nullptr);
  }

  // Remove a component
  template <typename T> void remove() { ecs_remove(m_world, m_entity, T); }

  // Check if entity is valid
  bool is_valid() const {
    return m_entity != 0 && ecs_is_valid(m_world, m_entity);
  }

  // Implicit conversion for Flecs interop
  operator ecs_entity_t() const { return m_entity; }

  ecs_entity_t id() const { return m_entity; }
  ecs_world_t *world() const { return m_world; }

private:
  ecs_entity_t m_entity;
  ecs_world_t *m_world;
};

} // namespace NEngine
