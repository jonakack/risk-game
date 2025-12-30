#include "gamestate_template.hpp"

// Constructor
GameState_Template::GameState_Template(Game *game)
{
    this->game = game;
};

void GameState_Template::handleInput()
{
    while (auto event = game->window.pollEvent())
    {
        // Close window if close button is pressed
        if (event->is<sf::Event::Closed>())
        {
            game->window.close();
            break;
        }
    }
}

void GameState_Template::update(const float dt)
{
}

void GameState_Template::draw(const float dt)
{
}