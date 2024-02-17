#include "World.h"

World::World(sf::Vector2u l_wind_size) {
    m_block_size = 16;
    m_window_size = l_wind_size;

    m_apple_shape.setFillColor(sf::Color::Red);
    m_apple_shape.setRadius(m_block_size / 2.0f);
    RespawnApple();

    for (int i = 0; i < 4; ++i) {
        m_bounds[i].setFillColor(sf::Color(0, 100, 0));
    }
    // top bound
    m_bounds[0].setSize(sf::Vector2f(m_window_size.x, m_block_size));
    // left bound
    m_bounds[1].setSize(sf::Vector2f(m_block_size, m_window_size.y));
    // right bound
    m_bounds[2].setPosition(sf::Vector2f(m_window_size.x - m_block_size, 0));
    m_bounds[2].setSize(sf::Vector2f(m_block_size, m_window_size.y));
    // bottom bound
    m_bounds[3].setPosition(
        sf::Vector2f(0, m_window_size.y - m_block_size * 2));
    m_bounds[3].setSize(sf::Vector2f(m_window_size.x, m_block_size * 2));
}

World::~World() {}

void World::RespawnApple() {
    srand(time(nullptr));
    int x_pos = (m_window_size.x / m_block_size) - 2;
    int y_pos = (m_window_size.y / m_block_size) - 3;
    m_item = sf::Vector2i(rand() % x_pos + 1, rand() % y_pos + 1);
    m_apple_shape.setPosition(m_item.x * m_block_size, m_item.y * m_block_size);
}

void World::Update(Player& l_player) {}

void World::Render(sf::RenderWindow& l_window) {
    for (int i = 0; i < 4; ++i) {
        l_window.draw(m_bounds[i]);
    }
    l_window.draw(m_apple_shape);
}

int World::GetBlockSize() { return m_block_size; }
