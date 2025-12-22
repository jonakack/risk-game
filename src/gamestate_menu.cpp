#include <SFML/Graphics.hpp>

#include "gamestate_menu.hpp"

// Constructor
GameState_Menu::GameState_Menu(Game *game)
{
    this->game = game;
};

void GameState_Menu::handleInput()
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

void GameState_Menu::update(const float dt)
{

}

void GameState_Menu::draw(const float dt)
{

}
