#include <SFML/Graphics.hpp>

class Textbox {
 public:
  Textbox(sf::Vector2u window_size);
  ~Textbox();
  void AddMessage(std::string message);
  void Render(sf::RenderWindow& window, sf::Vector2u window_size);

 private:
  int num_visible;
  int width;
  sf::Font font;
  sf::RectangleShape backdrop;
  sf::Text content;
  std::string message;
};
