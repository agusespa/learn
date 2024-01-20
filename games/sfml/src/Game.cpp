#include "Game.h"

void main(int argc, void** argv[]) {
    Game game;
    while (!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render();
    }
}
