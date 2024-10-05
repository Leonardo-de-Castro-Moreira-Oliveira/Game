#include "../../include/core/Entity.hpp"

core::Entity::Entity(const sf::Vector2f &position, const sf::Vector2f &scale,
                     NodeType nodeType, unsigned int health)
    : core::Node(position, scale, nodeType), health(health) {}

void core::Entity::takeDamage(unsigned int damage) {
  int updatedHealth = health - damage;
  health = (updatedHealth <= 0) ? 0 : updatedHealth;
}

bool core::Entity::isDead() const { return health == 0; }
