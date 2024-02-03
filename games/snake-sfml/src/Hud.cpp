#include "Hud.h"

#include "Snake.h"

Hud::Hud(int l_blockSize, sf::Vector2u l_windSize) {
    m_size = l_blockSize;
    m_windowSize = l_windSize;
    Reset();
}

Hud::~Hud() {}

void Hud::Reset() {
    for (int i = 0; i < 3; ++i) {
        m_hearts[i].setSize(sf::Vector2f(m_size - 2, m_size - 2));
        // TODO: use dynamic size
        m_hearts[i].setOrigin(7.0f, 7.0f);
        m_hearts[i].setFillColor(sf::Color(0, 0, 150));
        m_hearts[i].setRotation(45);
        m_hearts[i].setPosition(
            sf::Vector2f(m_size * (i + 1) * 2, m_windowSize.y - m_size));
    }
}

void Hud::Update(Snake& l_player) {
    for (int i = l_player.GetLives(); i < 3; ++i) {
        m_hearts[i].setFillColor(sf::Color(0, 150, 0));
    }
}

void Hud::Render(sf::RenderWindow& l_window) {
    for (int i = 0; i < 3; ++i) {
        l_window.draw(m_hearts[i]);
    }
}
