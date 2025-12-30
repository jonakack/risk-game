#include "map.hpp"

Map::Map(Game *game)
{
    this->game = game;

    loadDisplayMap();
    loadCountryIdMap();

    scaleMapToWindow();
}

void Map::loadDisplayMap()
{
    if (displayImage.loadFromFile("textures/europe.png"))
    {
        if (displayTexture.loadFromImage(displayImage))
            displaySprite.emplace(displayTexture);
    }

    // ONLY FOR DEVELOPMENT
    // 50% transparent
    displaySprite->setColor(sf::Color(255, 255, 255, 128));
}

void Map::loadCountryIdMap()
{
    if (countryIdImage.loadFromFile("textures/europe_idmap.png"))
    {
        if (countryIdTexture.loadFromImage(countryIdImage))
            countryIdSprite.emplace(countryIdTexture);
    }
}

void Map::scaleMapToWindow()
{
    auto textureSize = displayTexture.getSize();
    auto windowSize = game->window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    
    // Apply identical scaling to both sprites
    displaySprite->setScale({scaleX, scaleY});
    countryIdSprite->setScale({scaleX, scaleY});
    
    displaySprite->setPosition({0.f, 0.f});
    countryIdSprite->setPosition({0.f, 0.f});
}

// Check the countryIdMap to see what color is at the mouse position
sf::Color Map::getCountryIdColor(sf::Vector2f worldPos)
{
    if (!countryIdSprite)
        return sf::Color::Transparent;

    sf::Transform transform = countryIdSprite->getInverseTransform();
    
    sf::Vector2f localPos = transform.transformPoint(worldPos);

    // Check bounds
    if (localPos.x < 0 || localPos.y < 0 ||
        localPos.x >= countryIdImage.getSize().x ||
        localPos.y >= countryIdImage.getSize().y)
    {
        return sf::Color::Transparent;
    }

    return countryIdImage.getPixel({static_cast<unsigned int>(localPos.x + 0.5f), 
                                     static_cast<unsigned int>(localPos.y + 0.5f)});
}