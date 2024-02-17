#include "Hud.h"

#include "Snake.h"

Hud::Hud(int b_size, sf::Vector2u w_size) {
    block_size = b_size;
    window_size = w_size;
    heart_texture.loadFromFile("assets/heart.png");
    Reset();
}

Hud::~Hud() {}

void Hud::Reset() {
    for (int i = 0; i < 3; ++i) {
        hearts[i].setTexture(heart_texture);
        hearts[i].setScale(0.3, 0.3);
        sf::FloatRect bounds = hearts[i].getGlobalBounds();
        hearts[i].setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
        hearts[i].setPosition(
            sf::Vector2f(block_size * (i + 1) * 2, window_size.y - bounds.height - 6));
    }
}

void Hud::Update(Snake& player) {
    for (int i = player.GetLives(); i < 3; ++i) {
        hearts[i].setColor(sf::Color::Transparent);
    }
}

void Hud::Render(sf::RenderWindow& window) {
    for (int i = 0; i < 3; ++i) {
        window.draw(hearts[i]);
    }
}
