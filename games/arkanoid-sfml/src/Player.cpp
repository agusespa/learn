#include "Player.h"

Player::Player(int l_block_size) {
    m_size = l_block_size;
    m_body_rect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
    Reset();
}

Player::~Player() {}

void Player::Reset() {
    m_speed = 6;
    m_lives = 3;
    m_score = 0;
    m_lost = false;
}

int Player::GetSpeed() {
    int adjustedSpeed = m_speed;
    return adjustedSpeed;
}

int Player::GetLives() { return m_lives; }

int Player::GetScore() { return m_score; }

void Player::IncreaseScore() { m_score += 10; }

bool Player::HasLost() { return m_lost; }

void Player::Lose() {
    m_lost = true;
    m_lives = 0;
}

void Player::Move() {}

void Player::Render(sf::RenderWindow& l_window) {
    m_body_rect.setFillColor(sf::Color(255, 255, 0));
    l_window.draw(m_body_rect);
    m_body_rect.setFillColor(sf::Color::White);
}
