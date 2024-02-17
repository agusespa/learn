#include "Snake.h"
#include <iostream>

Snake::Snake(int block_size) {
    size = block_size;
    body_rect.setSize(sf::Vector2f(size - 1, size - 1));
    Reset();
}

Snake::~Snake() {}

void Snake::Reset() {
    snake_body.clear();
    snake_body.push_back(SnakeSegment(5, 7));
    snake_body.push_back(SnakeSegment(5, 6));
    snake_body.push_back(SnakeSegment(5, 5));
    SetDirection(Direction::Down);
    speed = 6;
    lives = 3;
    score = 0;
    lost = false;
}

void Snake::SetDirection(Direction dir) { dir = dir; }

Direction Snake::GetDirection() {
    if (snake_body.size() <= 1) {
        return Direction::None;
    }
    SnakeSegment& head = snake_body[0];
    SnakeSegment& neck = snake_body[1];
    if (head.position.x == neck.position.x) {
        return (head.position.y > neck.position.y ? Direction::Down
                                                  : Direction::Up);
    } else if (head.position.y == neck.position.y) {
        return (head.position.x > neck.position.x ? Direction::Right
                                                  : Direction::Left);
    }
    return Direction::None;
}

int Snake::GetSpeed() {
    int adjustedSpeed = speed + ((snake_body.size() - 2) / 2);
    return adjustedSpeed;
}

sf::Vector2i Snake::GetPosition() {
    return (!snake_body.empty() ? snake_body.front().position
                                : sf::Vector2i(1, 1));
}

int Snake::GetLives() { return lives; }

int Snake::GetScore() { return score; }

void Snake::IncreaseScore() { score += 10; }

bool Snake::HasLost() { return lost; }

void Snake::Lose() {
    lost = true;
    snake_body.clear();
    lives = 0;
}

void Snake::Extend() {
    if (snake_body.empty()) {
        return;
    }

    SnakeSegment& tail_head = snake_body[snake_body.size() - 1];

    if (snake_body.size() > 1) {
        SnakeSegment& tail_bone = snake_body[snake_body.size() - 2];
        if (tail_head.position.x == tail_bone.position.x) {
            if (tail_head.position.y > tail_bone.position.y) {
                snake_body.push_back(
                    SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
            } else {
                snake_body.push_back(
                    SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
            }
        } else if (tail_head.position.y == tail_bone.position.y) {
            if (tail_head.position.x > tail_bone.position.x) {
                snake_body.push_back(
                    SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
            } else {
                snake_body.push_back(
                    SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
            }
        }
    } else {
        if (dir == Direction::Up) {
            snake_body.push_back(
                SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
        } else if (dir == Direction::Down) {
            snake_body.push_back(
                SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
        } else if (dir == Direction::Left) {
            snake_body.push_back(
                SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
        } else if (dir == Direction::Right) {
            snake_body.push_back(
                SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
        }
    }
}

void Snake::Tick() {
    if (snake_body.empty()) {
        return;
    }

    if (dir == Direction::None) {
        return;
    }

    Move();
    CheckCollision();
}

void Snake::Move() {
    for (int i = snake_body.size() - 1; i > 0; --i) {
        snake_body[i].position = snake_body[i - 1].position;
    }
    if (dir == Direction::Left) {
        --snake_body[0].position.x;
    } else if (dir == Direction::Right) {
        ++snake_body[0].position.x;
    } else if (dir == Direction::Up) {
        --snake_body[0].position.y;
    } else if (dir == Direction::Down) {
        ++snake_body[0].position.y;
    }
}

void Snake::CheckCollision() {
    if (snake_body.size() < 5) {
        return;
    }

    SnakeSegment& head = snake_body.front();

    for (auto itr = snake_body.begin() + 1; itr != snake_body.end(); ++itr) {
        if (itr->position == head.position) {
            int segments = snake_body.end() - itr;
            Cut(segments);
            break;
        }
    }
}

void Snake::Cut(int segments) {
    std::cout << "cut " << segments << std::endl;
    for (int i = 0; i < segments; ++i) {
        snake_body.pop_back();
    }
    lives--;
    if (lives == 0) {
        Lose();
        return;
    }
}

void Snake::Render(sf::RenderWindow& window) {
    if (snake_body.empty()) {
        return;
    }

    auto head = snake_body.begin();
    body_rect.setFillColor(sf::Color(255, 255, 0));
    body_rect.setPosition(head->position.x * size, head->position.y * size);

    window.draw(body_rect);
    body_rect.setFillColor(sf::Color::White);

    for (auto itr = snake_body.begin() + 1; itr != snake_body.end(); ++itr) {
        body_rect.setPosition(itr->position.x * size, itr->position.y * size);
        window.draw(body_rect);
    }
}
