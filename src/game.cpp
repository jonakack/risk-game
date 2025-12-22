#include "game.hpp"
#include "gamestate.hpp"

// Constructor
Game::Game()
{
    window.create(sf::VideoMode({1920, 1080}), "Risk");
    window.setFramerateLimit(300);
}

void Game::gameLoop()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (peekState() == nullptr)
            continue;

        peekState()->handleInput();

        peekState()->update(dt);

        window.clear(sf::Color::Black);
        peekState()->draw(dt);
        window.display();
    }
}

// Destructor
Game::~Game()
{
    while (!states.empty())
        popState();
}

void Game::pushState(GameState *state)
{
    states.push(state);

    return;
}

void Game::popState()
{
    delete states.top();
    states.pop();

    return;
}

void Game::changeState(GameState *state)
{
    if (!states.empty())
        popState();
    pushState(state);

    return;
}

GameState *Game::peekState()
{
    if (states.empty())
        return nullptr;
    return states.top();
}