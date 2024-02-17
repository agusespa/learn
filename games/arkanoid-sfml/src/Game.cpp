#include "Game.h"

#include <SFML/Graphics.hpp>

Game::Game()
    : m_window("Arkanoid", sf::Vector2u(900, 600)),
      m_player(m_world.GetBlockSize()),
      m_hud(m_world.GetBlockSize(), m_window.GetWindowSize()),
      m_textbox(m_window.GetWindowSize()),
      m_world(m_window.GetWindowSize()) {}

Game::~Game() {}

void Game::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    }
}

void Game::Update() {
    m_window.Update();
    m_elapsed = GetElapsed();
    float timestep = 1.0f / m_player.GetSpeed();
    if (m_elapsed.asSeconds() >= timestep) {
        m_world.Update(m_player);
        m_hud.Update(m_player);
        RestartClock();

        if (m_player.HasLost()) {
            m_textbox.AddMessage("GAME OVER!\nScore: " +
                                 std::to_string(m_player.GetScore()));
        }
    }
}

void Game::Render() {
    m_window.BeginDraw();

    m_world.Render(*m_window.GetRenderWindow());
    m_player.Render(*m_window.GetRenderWindow());
    m_hud.Render(*m_window.GetRenderWindow());
    m_textbox.Render(*m_window.GetRenderWindow(), m_window.GetWindowSize());

    m_window.EndDraw();
}

sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }

void Game::RestartClock() { m_elapsed = m_clock.restart(); }

Window* Game::GetWindow() { return &m_window; }
