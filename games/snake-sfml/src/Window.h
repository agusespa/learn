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
  void Setup(const string& l_title, const sf::Vector2u& l_size);
  void Create();
  void Destroy();

  sf::RenderWindow m_window;
  sf::Vector2u m_windowSize;
  string m_windowTitle;
  bool m_isDone;
};
