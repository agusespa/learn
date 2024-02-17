#include "Snake.h"

Snake::Snake(int l_block_size) {
    m_size = l_block_size;
    m_body_rect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
    Reset();
}

Snake::~Snake() {}

void Snake::Reset() {
    m_snake_body.clear();
    m_snake_body.push_back(SnakeSegment(5, 7));
    m_snake_body.push_back(SnakeSegment(5, 6));
    m_snake_body.push_back(SnakeSegment(5, 5));
    SetDirection(Direction::Down);
    m_speed = 6;
    m_lives = 3;
    m_score = 0;
    m_lost = false;
}

void Snake::SetDirection(Direction l_dir) { m_dir = l_dir; }

Direction Snake::GetDirection() {
    if (m_snake_body.size() <= 1) {
        return Direction::None;
    }
    SnakeSegment& head = m_snake_body[0];
    SnakeSegment& neck = m_snake_body[1];
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
    int adjustedSpeed = m_speed + ((m_snake_body.size() - 2) / 2);
    return adjustedSpeed;
}

sf::Vector2i Snake::GetPosition() {
    return (!m_snake_body.empty() ? m_snake_body.front().position
                                 : sf::Vector2i(1, 1));
}

int Snake::GetLives() { return m_lives; }

int Snake::GetScore() { return m_score; }

void Snake::IncreaseScore() { m_score += 10; }

bool Snake::HasLost() { return m_lost; }

void Snake::Lose() {
    m_lost = true;
    m_snake_body.clear();
    m_lives = 0;
}

void Snake::Extend() {
    if (m_snake_body.empty()) {
        return;
    }

    SnakeSegment& tail_head = m_snake_body[m_snake_body.size() - 1];

    if (m_snake_body.size() > 1) {
        SnakeSegment& tail_bone = m_snake_body[m_snake_body.size() - 2];
        if (tail_head.position.x == tail_bone.position.x) {
            if (tail_head.position.y > tail_bone.position.y) {
                m_snake_body.push_back(SnakeSegment(tail_head.position.x,
                                                   tail_head.position.y + 1));
            } else {
                m_snake_body.push_back(SnakeSegment(tail_head.position.x,
                                                   tail_head.position.y - 1));
            }
        } else if (tail_head.position.y == tail_bone.position.y) {
            if (tail_head.position.x > tail_bone.position.x) {
                m_snake_body.push_back(SnakeSegment(tail_head.position.x + 1,
                                                   tail_head.position.y));
            } else {
                m_snake_body.push_back(SnakeSegment(tail_head.position.x - 1,
                                                   tail_head.position.y));
            }
        }
    } else {
        if (m_dir == Direction::Up) {
            m_snake_body.push_back(
                SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
        } else if (m_dir == Direction::Down) {
            m_snake_body.push_back(
                SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
        } else if (m_dir == Direction::Left) {
            m_snake_body.push_back(
                SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
        } else if (m_dir == Direction::Right) {
            m_snake_body.push_back(
                SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
        }
    }
}

void Snake::Tick() {
    if (m_snake_body.empty()) {
        return;
    }

    if (m_dir == Direction::None) {
        return;
    }

    Move();
    CheckCollision();
}

void Snake::Move() {
    for (int i = m_snake_body.size() - 1; i > 0; --i) {
        m_snake_body[i].position = m_snake_body[i - 1].position;
    }
    if (m_dir == Direction::Left) {
        --m_snake_body[0].position.x;
    } else if (m_dir == Direction::Right) {
        ++m_snake_body[0].position.x;
    } else if (m_dir == Direction::Up) {
        --m_snake_body[0].position.y;
    } else if (m_dir == Direction::Down) {
        ++m_snake_body[0].position.y;
    }
}

void Snake::CheckCollision() {
    if (m_snake_body.size() < 5) {
        return;
    }

    SnakeSegment& head = m_snake_body.front();

    for (auto itr = m_snake_body.begin() + 1; itr != m_snake_body.end(); ++itr) {
        if (itr->position == head.position) {
            int segments = m_snake_body.end() - itr;
            Cut(segments);
            break;
        }
    }
}

void Snake::Cut(int l_segments) {
    for (int i = 0; i < l_segments; ++i) {
        m_snake_body.pop_back();
    }
    m_lives--;
    if (m_lives == 0) {
        Lose();
        return;
    }
}

void Snake::Render(sf::RenderWindow& l_window) {
    if (m_snake_body.empty()) {
        return;
    }

    auto head = m_snake_body.begin();
    m_body_rect.setFillColor(sf::Color(255, 255, 0));
    m_body_rect.setPosition(head->position.x * m_size,
                           head->position.y * m_size);

    l_window.draw(m_body_rect);
    m_body_rect.setFillColor(sf::Color::White);

    for (auto itr = m_snake_body.begin() + 1; itr != m_snake_body.end(); ++itr) {
        m_body_rect.setPosition(itr->position.x * m_size,
                               itr->position.y * m_size);
        l_window.draw(m_body_rect);
    }
}
