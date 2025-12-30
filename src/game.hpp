#pragma once

#include <stack>

#include <SFML/Graphics.hpp>

#include "textures.hpp"

class GameState;

class Game
{
public:
    Game();
    ~Game();

    void gameLoop();
    void pushState(GameState *state);
    void popState();
    void changeState(GameState *state);
    GameState *peekState();

    std::stack<GameState *> states;
    sf::RenderWindow window;
    
};