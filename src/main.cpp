#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "gamestate_menu.hpp"

int main()
{
    Game game;

    // Automatically push GameState_Menu to state stack on startup
    game.pushState(new GameState_Menu(&game));
    game.gameLoop();

    return 0;
}
