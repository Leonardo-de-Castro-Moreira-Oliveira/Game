#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>

struct Game {
public:
  Game(int width, int height, const char *title);
  void run();

private:
  void processEvents();
  void update();
  void draw();

  std::shared_ptr<sf::RenderWindow> win;
  sf::Clock clock;
};

#endif
