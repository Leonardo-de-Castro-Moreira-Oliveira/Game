#include "Core.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

class core::Node : public std::enable_shared_from_this<Node> {
public:
  Node(const sf::Vector2f &position, const sf::Vector2f &scale,
       NodeType nodeType);
  ~Node() = default;

  bool operator==(const Node &other) const;

  sf::FloatRect getGlobalBounds() const;
  NodeType getNodeType() const;

  virtual void draw(std::shared_ptr<sf::RenderWindow> win) const = 0;
  virtual void update(float deltaTime) = 0;

protected:
  std::shared_ptr<sf::Sprite> sprite;
  NodeType nodeType;
};
