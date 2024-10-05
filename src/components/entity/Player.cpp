#include "../../../include/components/entity/Player.hpp"
#include "../../../include/components/Input.hpp"
#include "../../../include/components/NodeType.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <memory>

entity::Player::Player(const sf::Vector2f &position, const sf::Vector2f &scale,
                       unsigned int health, float speed)
    : core::Entity(position, scale, core::NodeType::ENTITY_PLAYER, health),
      speed(speed) {
  sf::Texture texture;
  if (!texture.loadFromFile("assets/vguy/Jump (32x32).png")) {
    std::cout << "Loaded!";
  };
  sprite->setTexture(texture);
}

void entity::Player::draw(std::shared_ptr<sf::RenderWindow> win) const {
  win->draw(*sprite);
}

void entity::Player::update(float deltaTime) { move(deltaTime); }

void entity::Player::move(float deltaTime) {
  float mv = deltaTime * speed;

  if (input::north() && input::east()) {
    sprite->setRotation(45.f);
    sprite->move(sf::Vector2f(mv, -mv));
  } else if (input::north() && input::west()) {
    sprite->setRotation(315.f);
    sprite->move(sf::Vector2f(-mv, -mv));
  } else if (input::south() && input::east()) {
    sprite->setRotation(135.f);
    sprite->move(sf::Vector2f(mv, mv));
  } else if (input::south() && input::west()) {
    sprite->setRotation(225.f);
    sprite->move(sf::Vector2f(-mv, mv));
  } else if (input::north()) {
    sprite->setRotation(0.f);
    sprite->move(sf::Vector2f(0, -mv));
  } else if (input::south()) {
    sprite->setRotation(180.f);
    sprite->move(sf::Vector2f(0, mv));
  } else if (input::east()) {
    sprite->setRotation(90.f);
    sprite->move(sf::Vector2f(mv, 0));
  } else if (input::west()) {
    sprite->setRotation(270.f);
    sprite->move(sf::Vector2f(-mv, 0));
  }
}
