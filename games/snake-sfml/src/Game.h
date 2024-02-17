#include "Hud.h"
#include "Snake.h"
#include "Textbox.h"
#include "Window.h"
#include "World.h"

class Game {
 public:
  Game();
  ~Game();

  void HandleInput();
  void Update();
  void Render();
  Window* GetWindow();

 private:
  sf::Time GetElapsed();
  void RestartClock();

  sf::Clock m_clock;
  sf::Time m_elapsed;
  Window m_window;
  World m_world;
  Snake m_snake;
  Hud m_hud;
  Textbox m_textbox;
};
