#pragma once
#include <SFML/Graphics.hpp>

class Player {
 public:
  Player(int l_block_size);
  ~Player();
  int GetSpeed();
  sf::Vector2i GetPosition();
  int GetLives();
  int GetScore();
  void IncreaseScore();
  bool HasLost();
  void Lose();
  void Reset();
  void Move();
  void Render(sf::RenderWindow& l_window);

 private:
  int m_size;
  int m_speed;
  int m_lives;
  int m_score;
  bool m_lost;
  sf::RectangleShape m_body_rect;
};
