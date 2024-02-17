#include "Hud.h"

#include "Snake.h"

Hud::Hud(int l_block_size, sf::Vector2u l_wind_size) {
    m_size = l_block_size;
    m_window_size = l_wind_size;
    m_heart_texture.loadFromFile("assets/heart.png");
    Reset();
}

Hud::~Hud() {}

void Hud::Reset() {
    for (int i = 0; i < 3; ++i) {
        m_hearts[i].setTexture(m_heart_texture);
        m_hearts[i].setScale(0.3, 0.3);
        sf::FloatRect bounds = m_hearts[i].getGlobalBounds();
        m_hearts[i].setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
        m_hearts[i].setPosition(
            sf::Vector2f(m_size * (i + 1) * 2, m_window_size.y - bounds.height - 6));
    }
}

void Hud::Update(Snake& l_player) {
    for (int i = l_player.GetLives(); i < 3; ++i) {
        m_hearts[i].setColor(sf::Color::Transparent);
    }
}

void Hud::Render(sf::RenderWindow& l_window) {
    for (int i = 0; i < 3; ++i) {
        l_window.draw(m_hearts[i]);
    }
}
