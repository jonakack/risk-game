#include <SFML/Graphics.hpp>

#include "src/game.hpp"
#include "src/gamestate_menu.hpp"
#include "src/gamestate_europe.hpp"

int main()
{
    Game game;

    // Automatically push GameState_Menu to state stack on startup
    game.pushState(new GameState_Europe(&game));
    // game.pushState(new GameState_Menu(&game));
    game.gameLoop();

    return 0;
}