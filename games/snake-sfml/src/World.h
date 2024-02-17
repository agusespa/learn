#include <SFML/Graphics.hpp>

#include "Snake.h"

class World {
 public:
  World(sf::Vector2u window_size);
  ~World();
  int GetBlockSize();
  void RespawnApple();
  void Update(Snake& player);
  void Render(sf::RenderWindow& window);

 private:
  sf::Vector2u size;
  sf::Vector2i item;
  int block_size;
  sf::CircleShape apple_shape;
  sf::RectangleShape bounds[4];
};
