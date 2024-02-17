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
  void RestartClock();
  sf::Time GetElapsed();

  sf::Clock clock;
  sf::Time elapsed;
  Window window;
  World world;
  Snake snake;
  Hud hud;
  Textbox textbox;
};
