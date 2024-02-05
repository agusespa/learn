#include <SFML/Graphics.hpp>

class Textbox {
 public:
  Textbox(sf::Vector2u l_windSize);
  ~Textbox();
  void AddMessage(std::string l_message);
  void Render(sf::RenderWindow& l_wind);

 private:
  int m_numVisible;
  int m_width;
  sf::RectangleShape m_backdrop;
  sf::Text m_content;
  std::string m_message;
};
