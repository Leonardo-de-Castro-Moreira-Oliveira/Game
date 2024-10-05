#include "../../include/core/Node.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

core::Node::Node(const sf::Vector2f &position, const sf::Vector2f &scale,
                 NodeType nodeType)
    : sprite(std::make_shared<sf::Sprite>()), nodeType(nodeType) {
  sprite->setPosition(position);
  sprite->setScale(scale);
}

bool core::Node::operator==(const Node &other) const {
  return nodeType == other.getNodeType();
}

core::NodeType core::Node::getNodeType() const { return nodeType; }

sf::FloatRect core::Node::getGlobalBounds() const {
  return sprite->getGlobalBounds();
}
