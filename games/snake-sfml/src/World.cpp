#include "World.h"

World::World(sf::Vector2u l_windSize) {
    m_blockSize = 16;
    m_windowSize = l_windSize;

    srand(time(nullptr));

    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize / 2);
    RespawnApple();

    for (int i = 0; i < 4; ++i) {
        m_bounds[i].setFillColor(sf::Color(0, 150, 0));
    }
    // top bound
    m_bounds[0].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
    // left bound
    m_bounds[1].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
    // right bound
    m_bounds[2].setPosition(sf::Vector2f(m_windowSize.x - m_blockSize, 0));
    m_bounds[2].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
    // bottom bound
    m_bounds[3].setPosition(sf::Vector2f(0, m_windowSize.y - m_blockSize * 2));
    m_bounds[3].setSize(sf::Vector2f(m_windowSize.x, m_blockSize * 2));
}

World::~World() {}

void World::RespawnApple() {
    int maxX = (m_windowSize.x / m_blockSize) - 2;
    int maxY = (m_windowSize.y / m_blockSize) - 2;
    m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
    m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
}

void World::Update(Snake& l_player) {
    if (l_player.GetPosition() == m_item) {
        l_player.Extend();
        l_player.IncreaseScore();
        RespawnApple();
    }

    int gridSize_x = m_windowSize.x / m_blockSize;
    int gridSize_y = m_windowSize.y / m_blockSize;

    if (l_player.GetPosition().x <= 0 || l_player.GetPosition().y <= 0 ||
        l_player.GetPosition().x >= gridSize_x - 1 ||
        l_player.GetPosition().y >= gridSize_y - 2) {
        l_player.Lose();
    }
}

void World::Render(sf::RenderWindow& l_window) {
    for (int i = 0; i < 4; ++i) {
        l_window.draw(m_bounds[i]);
    }
    l_window.draw(m_appleShape);
}

int World::GetBlockSize() { return m_blockSize; }
