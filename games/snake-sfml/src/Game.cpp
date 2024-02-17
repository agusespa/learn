#include "Game.h"

#include <SFML/Graphics.hpp>

Game::Game()
    : window("Snake", sf::Vector2u(496, 512)),
      snake(world.GetBlockSize()),
      hud(world.GetBlockSize(), window.GetWindowSize()),
      textbox(window.GetWindowSize()),
      world(sf::Vector2u(496, 512)) {}

Game::~Game() {}

void Game::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        snake.GetDirection() != Direction::Down) {
        snake.SetDirection(Direction::Up);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
               snake.GetDirection() != Direction::Up) {
        snake.SetDirection(Direction::Down);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
               snake.GetDirection() != Direction::Right) {
        snake.SetDirection(Direction::Left);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
               snake.GetDirection() != Direction::Left) {
        snake.SetDirection(Direction::Right);
    }
}

void Game::Update() {
    window.Update();
    elapsed = GetElapsed();
    float timestep = 1.0f / snake.GetSpeed();
    if (elapsed.asSeconds() >= timestep) {
        snake.Tick();
        world.Update(snake);
        hud.Update(snake);
        RestartClock();

        if (snake.HasLost()) {
            textbox.AddMessage("GAME OVER!\nScore: " +
                               std::to_string(snake.GetScore()));
        }
    }
}

void Game::Render() {
    window.BeginDraw();

    world.Render(*window.GetRenderWindow());
    snake.Render(*window.GetRenderWindow());
    hud.Render(*window.GetRenderWindow());
    textbox.Render(*window.GetRenderWindow(), window.GetWindowSize());

    window.EndDraw();
}

sf::Time Game::GetElapsed() { return clock.getElapsedTime(); }

void Game::RestartClock() { elapsed = clock.restart(); }

Window* Game::GetWindow() { return &window; }
