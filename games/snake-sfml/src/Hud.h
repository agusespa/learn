#include <SFML/Graphics.hpp>
#include "Snake.h"

class Hud {
 public:
  Hud(int b_size, sf::Vector2u window_size);
  ~Hud();
  void Reset();
  void Update(Snake& player);
  void Render(sf::RenderWindow& window);

 private:
  int block_size;
  sf::Vector2u window_size;
  sf::Texture heart_texture;
  sf::Sprite hearts[3];
};
