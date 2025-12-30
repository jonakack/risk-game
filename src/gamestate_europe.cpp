#include <iostream>
#include "gamestate_europe.hpp"

// Constructor
GameState_Europe::GameState_Europe(Game *game)
    : map(game)
{
    this->game = game;
};

void GameState_Europe::handleInput()
{
    while (auto event = game->window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            game->window.close();
            break;
        }

        if (event->is<sf::Event::Resized>())
        {
            auto size = event->getIf<sf::Event::Resized>();
            sf::View view(sf::FloatRect({0, 0}, {static_cast<float>(size->size.x),
                                                 static_cast<float>(size->size.y)}));
            game->window.setView(view);
            map.scaleMapToWindow();
            currentZoom = 1.0f; // Reset zoom level on resize
        }

        // Mouse wheel zoom
        if (auto *scroll = event->getIf<sf::Event::MouseWheelScrolled>())
        {
            if (scroll->wheel == sf::Mouse::Wheel::Vertical)
            {
                // Calculate new zoom level
                float zoomFactor = (scroll->delta > 0) ? 0.9f : 1.1f;
                float newZoom = currentZoom * zoomFactor;

                // Limit zoom: 100% (no zoom out) to 150% (1.5x zoomed in)
                if (newZoom > 1.0f || newZoom < (1.0f / 1.5f))
                    continue;

                sf::Vector2i pixelPos = sf::Mouse::getPosition(game->window);

                sf::Vector2f worldPosBeforeZoom = game->window.mapPixelToCoords(pixelPos);

                // Apply zoom
                sf::View view = game->window.getView();
                view.zoom(zoomFactor);
                game->window.setView(view);

                currentZoom = newZoom;

                // Convert same pixel position to world coordinates (after zoom)
                sf::Vector2f worldPosAfterZoom = game->window.mapPixelToCoords(pixelPos);

                // Move view to keep mouse position fixed
                sf::Vector2f offset = worldPosBeforeZoom - worldPosAfterZoom;
                view.move(offset);
                game->window.setView(view);
            }
        }

        if (event->is<sf::Event::MouseButtonPressed>())
        {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(game->window);
            sf::Vector2f worldPos = game->window.mapPixelToCoords(pixelPos);

            sf::Color idColor = map.getCountryIdColor(worldPos);
            std::cout << "Country ID color: "
                      << (int)idColor.r << ", "
                      << (int)idColor.g << ", "
                      << (int)idColor.b << "\n";
        }
    }
}

void GameState_Europe::update(const float dt)
{
}

void GameState_Europe::draw(const float dt)
{
    game->window.draw(*map.countryIdSprite); // ONLY FOR DEVELOPMENT - Draw ID map
    game->window.draw(*map.displaySprite);
}