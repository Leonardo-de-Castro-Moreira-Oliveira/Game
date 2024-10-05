#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "../../core/Entity.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace entity {
class Player : public core::Entity {
public:
  Player(const sf::Vector2f &position, const sf::Vector2f &scale,
         core::NodeType nodeType, unsigned int health, float speed);

  void draw(std::shared_ptr<sf::RenderWindow> win) const override;
  void update(float deltaTime) override;

private:
  void move(float deltaTime);

  float speed;
};
} // namespace entity

#endif
