#include <SFML/Graphics.hpp>

using namespace std;

class Window {
 public:
  Window(const string& l_title, const sf::Vector2u& l_size);
  ~Window();

  void BeginDraw();
  void Draw(sf::Drawable& l_drawable);
  void EndDraw();
  void Update();
  bool IsDone();

  sf::RenderWindow* GetRenderWindow();
  sf::Vector2u GetWindowSize();

 private:
  sf::RenderWindow m_window;
  sf::Vector2u m_window_size;
  string m_window_title;
  bool m_is_done;
};
