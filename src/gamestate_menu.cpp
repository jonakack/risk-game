#include "gamestate_menu.hpp"

// Constructor
GameState_Menu::GameState_Menu(Game *game)
{
    this->game = game;

    loadBackground();
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
        if (auto *Keypressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (Keypressed->code == sf::Keyboard::Key::Space)
                game->window.close();
        }
    }
}

void GameState_Menu::update(const float dt)
{
}

void GameState_Menu::draw(const float dt)
{
    game->window.draw(*backgroundSprite);
}

void GameState_Menu::loadBackground()
{
    // Create background texture and fill sprite
    if (backgroundTexture.loadFromFile("textures/worldmap.png"))
        backgroundSprite.emplace(backgroundTexture);

    // Scale background sprite to fit the window
    if (backgroundSprite)
    {
        auto textureSize = backgroundTexture.getSize();
        auto windowSize = game->window.getSize();

        float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
        float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
        float scale = std::max(scaleX, scaleY); // Use the larger scale

        backgroundSprite->setScale({scale, scale});

        // Center the sprite in the window
        float offsetX = (windowSize.x - textureSize.x * scale) / 2.f;
        float offsetY = (windowSize.y - textureSize.y * scale) / 2.f;
        backgroundSprite->setPosition({offsetX, offsetY});
    }
}