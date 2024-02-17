#include <SFML/Graphics.hpp>

class Textbox {
 public:
  Textbox(sf::Vector2u l_wind_size);
  ~Textbox();
  void AddMessage(std::string l_message);
  void Render(sf::RenderWindow& l_wind, sf::Vector2u l_wind_size);

 private:
  int m_num_visible;
  int m_width;
  sf::Font font;
  sf::RectangleShape m_backdrop;
  sf::Text m_content;
  std::string m_message;
};
