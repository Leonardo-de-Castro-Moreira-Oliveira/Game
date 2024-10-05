#ifndef ENTITY_INCLUDED
#define ENTITY_INCLUDED

#include "Node.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class core::Entity : public core::Node {
public:
  Entity(const sf::Vector2f &position, const sf::Vector2f &scale,
         NodeType nodeType, unsigned int health);

  void takeDamage(unsigned int damage);
  bool isDead() const;

  virtual void draw(std::shared_ptr<sf::RenderWindow> win) const override = 0;
  virtual void update(float deltaTime) override = 0;

protected:
  unsigned int health;
};

#endif
