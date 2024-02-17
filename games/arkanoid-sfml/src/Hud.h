#include <SFML/Graphics.hpp>
#include "Player.h"

class Hud {
 public:
  Hud(int l_block_size, sf::Vector2u l_wind_size);
  ~Hud();
  void Reset();
  void Update(Player& l_player);
  void Render(sf::RenderWindow& l_window);

 private:
  int m_size;
  sf::Vector2u m_window_size;
  sf::Texture m_lives_texture;
  sf::Sprite m_lives[3];
};
