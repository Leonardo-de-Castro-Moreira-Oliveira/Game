#include "../../include/components/Input.hpp"
#include <SFML/Window/Keyboard.hpp>

bool input::east() {
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

bool input::west() {
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool input::north() {
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

bool input::south() {
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}
