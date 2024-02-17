#include <SFML/Graphics.hpp>

using namespace std;

class Window {
 public:
  Window(const string& title, const sf::Vector2u& size);
  ~Window();

  void BeginDraw();
  void Draw(sf::Drawable& drawable);
  void EndDraw();
  void Update();
  bool IsDone();
  sf::RenderWindow* GetRenderWindow();
  sf::Vector2u GetWindowSize();

 private:
  sf::RenderWindow window;
  sf::Vector2u window_size;
  bool is_done;
};
