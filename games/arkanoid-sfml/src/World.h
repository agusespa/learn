#include <SFML/Graphics.hpp>

#include "Player.h"

class World {
 public:
  World(sf::Vector2u l_wind_size);
  ~World();
  int GetBlockSize();
  void RespawnApple();
  void Update(Player& l_player);
  void Render(sf::RenderWindow& l_window);

 private:
  sf::Vector2u m_window_size;
  sf::Vector2i m_item;
  int m_block_size;
  sf::CircleShape m_apple_shape;
  sf::RectangleShape m_bounds[4];
};
