#include <flecs.h>

class Entity {
  flecs::world m_world;
  flecs::entity_t m_id;

public:
  Entity(flecs::world &world, flecs::entity_t id) : m_world(world), m_id(id) {}
  ~Entity() {}
  flecs::entity get() const { return m_world.entity(m_id); }
};
