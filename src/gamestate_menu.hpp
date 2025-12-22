#pragma once

#include "gamestate.hpp"

class GameState_Menu : public GameState
{
public:
    GameState_Menu(Game *game);

    virtual void handleInput();
    virtual void update(const float dt);
    virtual void draw(const float dt);
};