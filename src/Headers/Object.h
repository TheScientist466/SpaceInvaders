#pragma once

#include <SFML/Graphics.hpp>

class Object
{

public:
    Object();
    ~Object();

protected:
    sf::Texture* objectTexture;
    sf::Sprite objectSprite;

public:
    sf::Sprite getSprite() const;

    void setObjectTexture(const char* path);
    void setObjectTexture(const char* path, sf::IntRect r);

    void setObjectSpriteSize(sf::Vector2u size);
};