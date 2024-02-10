#include <SFML/Graphics.hpp>

using namespace std;

class Window {
  public:
   Window(const string& l_title, const sf::Vector2u& l_size);
   ~Window();

   void BeginDraw();
   void EndDraw();
   void Update();
   bool IsDone();
   bool IsFullscreen();
   void ToggleFullscreen();

   sf::RenderWindow* GetRenderWindow();
   sf::Vector2u GetWindowSize();

   void Draw(sf::Drawable& l_drawable);

  private:
   void Setup(const string& l_title, const sf::Vector2u& l_size);
   void Destroy();
   void Create();

   sf::RenderWindow m_window;
   sf::Vector2u m_windowSize;
   string m_windowTitle;
   bool m_isDone;
   bool m_isFullscreen;
};
