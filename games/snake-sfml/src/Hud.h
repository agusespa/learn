#include <SFML/Graphics.hpp>
#include "Snake.h"

class Hud {
 public:
  Hud(int l_blockSize, sf::Vector2u l_windSize);
  ~Hud();
  void Reset();
  void Update(Snake& l_player);
  void Render(sf::RenderWindow& l_window);

 private:
  int m_size;
  sf::Vector2u m_windowSize;
  sf::Texture heartTexture;
  sf::Sprite m_hearts[3];
};
