#include "Hud.h"

#include "Player.h"

Hud::Hud(int l_block_size, sf::Vector2u l_wind_size) {
    m_size = l_block_size;
    m_window_size = l_wind_size;
    m_lives_texture.loadFromFile("assets/platform.png");
    Reset();
}

Hud::~Hud() {}

void Hud::Reset() {
    for (int i = 0; i < 3; i++) {
        m_lives[i].setTexture(m_lives_texture);
        m_lives[i].setScale(0.35, 0.35);
        sf::FloatRect bounds = m_lives[i].getGlobalBounds();
        m_lives[i].setOrigin(0, bounds.height);
        m_lives[i].setPosition(
            sf::Vector2f(bounds.width * i + 20, m_window_size.y - 20));
    }
}

void Hud::Update(Player& l_player) {
    for (int i = l_player.GetLives(); i < 3; i++) {
        m_lives[i].setColor(sf::Color::Transparent);
    }
}

void Hud::Render(sf::RenderWindow& l_window) {
    for (int i = 0; i < 3; ++i) {
        l_window.draw(m_lives[i]);
    }
}
