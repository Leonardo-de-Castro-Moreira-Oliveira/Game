#include "../include/Game.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>

Game::Game(int width, int height, const char *title)
    : win(std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height),
                                             title)),
      player(std::make_shared<entity::Player>(
          sf::Vector2f((float)width / 2, (float)height / 2), sf::Vector2f(1, 1),
          100, 200.f)) {
  clock.restart();
}

void Game::run() {
  while (win->isOpen()) {
    processEvents();
    update();
    draw();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (win->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      win->close();
    }
  }
}

void Game::update() {
  float deltaTime = clock.restart().asSeconds();
  player->update(deltaTime);
}

void Game::draw() {
  win->clear();
  player->draw(win);
  win->display();
}
