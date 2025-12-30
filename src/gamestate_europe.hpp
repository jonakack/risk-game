#pragma once

#include <optional>

#include <SFML/Graphics.hpp>

#include "gamestate.hpp"
#include "map.hpp"

class GameState_Europe : public GameState
{
public:
    GameState_Europe(Game *game);

    virtual void handleInput();
    virtual void update(const float dt);
    virtual void draw(const float dt);

private:
    Map map;
    float currentZoom = 1.0f; // 1.0 = 100%
};