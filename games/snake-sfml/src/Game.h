#include "Snake.h"
#include "Window.h"
#include "World.h"
#include "Hud.h"
#include "Textbox.h"

class Game {
 public:
  Game();
  ~Game();

  void HandleInput();
  void Update();
  void Render();

  sf::Time GetElapsed();
  void RestartClock();

  Window* GetWindow();

 private:
  sf::Clock m_clock;
  sf::Time m_elapsed;

  Window m_window;
  World m_world;
  Snake m_snake;
  Hud m_hud;
  Textbox m_textbox;
};
