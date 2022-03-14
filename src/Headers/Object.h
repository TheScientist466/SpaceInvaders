#pragma once

#include <SFML/Graphics.hpp>

class Object
{

public:
    Object();
    ~Object();

private:
    sf::Texture* objectTexture;
    sf::Sprite objectSprite;

public:
    sf::Sprite getObjectSprite() const;

    void setObjectTexture(const char* path);
    void setObjectTexture(const char* path, sf::IntRect r);

    void setObjectSpriteSize(sf::Vector2i size);

    void setObjectPosition(sf::Vector2f newPos);
    void setObjectPosition(float x, float y);

};