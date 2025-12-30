#pragma once

#include <SFML/Graphics.hpp>

class TextureManager
{
public:
    // Constructor
    TextureManager();
    
    void loadTexture(std::string sprite, std::string texture);
    
};