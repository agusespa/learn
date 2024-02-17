#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct SnakeSegment {
  SnakeSegment(int x, int y) : position(x, y) {}
  sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake {
 public:
  Snake(int block_size);
  ~Snake();
  void SetDirection(Direction dir);
  Direction GetDirection();
  int GetSpeed();
  sf::Vector2i GetPosition();
  int GetLives();
  int GetScore();
  void IncreaseScore();
  bool HasLost();
  void Lose();
  void Extend();
  void Reset();
  void Move();
  void Tick();
  void Cut(int segments);
  void Render(sf::RenderWindow& window);

 private:
  void CheckCollision();
  SnakeContainer snake_body;
  int size;
  Direction dir;
  int speed;
  int lives;
  int score;
  bool lost;
  sf::RectangleShape body_rect;
};
