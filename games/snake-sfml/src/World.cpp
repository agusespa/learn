#include "World.h"

World::World(sf::Vector2u size) {
    block_size = 16;
    size = size;

    apple_shape.setFillColor(sf::Color::Red);
    apple_shape.setRadius(block_size / 2.0f);
    RespawnApple();

    for (int i = 0; i < 4; ++i) {
        bounds[i].setFillColor(sf::Color(0, 100, 0));
    }
    // top bound
    bounds[0].setSize(sf::Vector2f(size.x, block_size));
    // left bound
    bounds[1].setSize(sf::Vector2f(block_size, size.y));
    // right bound
    bounds[2].setPosition(sf::Vector2f(size.x - block_size, 0));
    bounds[2].setSize(sf::Vector2f(block_size, size.y));
    // bottom bound
    bounds[3].setPosition(sf::Vector2f(0, size.y - block_size * 2));
    bounds[3].setSize(sf::Vector2f(size.x, block_size * 2));
}

World::~World() {}

void World::RespawnApple() {
    srand(time(nullptr));
    int x_pos = (size.x / block_size) - 2;
    int y_pos = (size.y / block_size) - 3;
    item = sf::Vector2i(rand() % x_pos + 1, rand() % y_pos + 1);
    apple_shape.setPosition(item.x * block_size, item.y * block_size);
}

void World::Update(Snake& player) {
    if (player.GetPosition() == item) {
        player.Extend();
        player.IncreaseScore();
        RespawnApple();
    }

    int gridSize_x = size.x / block_size;
    int gridSize_y = size.y / block_size;

    if (player.GetPosition().x <= 0 || player.GetPosition().y <= 0 ||
        player.GetPosition().x >= gridSize_x - 1 ||
        player.GetPosition().y >= gridSize_y - 2) {
        player.Lose();
    }
}

void World::Render(sf::RenderWindow& window) {
    for (int i = 0; i < 4; ++i) {
        window.draw(bounds[i]);
    }
    window.draw(apple_shape);
}

int World::GetBlockSize() { return block_size; }
