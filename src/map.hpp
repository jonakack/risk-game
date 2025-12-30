#pragma once

#include <SFML/Graphics.hpp>

#include <unordered_map>

#include "game.hpp"

class Map
{
public:
    Map(Game *game);

    Game *game;

    void loadDisplayMap();
    void loadCountryIdMap();
    void scaleMapToWindow();
    sf::Color getCountryIdColor(sf::Vector2f worldPos);

    // Hidden key map
    sf::Image countryIdImage;
    sf::Texture countryIdTexture;
    std::optional<sf::Sprite> countryIdSprite;

    // Map that player can see
    sf::Image displayImage;
    sf::Texture displayTexture;
    std::optional<sf::Sprite> displaySprite;

    // std::unordered_map<country>
};