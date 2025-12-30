#pragma once

#include <optional>

#include <SFML/Graphics.hpp>

#include "gamestate.hpp"

class GameState_Template : public GameState
{
public:
    GameState_Template(Game *game);

    virtual void handleInput();
    virtual void update(const float dt);
    virtual void draw(const float dt);

private:

};