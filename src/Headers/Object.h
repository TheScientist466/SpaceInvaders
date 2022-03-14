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
    sf::Vector2f position;

public:
    float moveSpeed = 0.f;

public:
    sf::Sprite getSprite() const;

    void setObjectTexture(const char* path);
    void setObjectTexture(const char* path, sf::IntRect r);

    void setObjectSpriteSize(sf::Vector2u size);

    void setPosition(sf::Vector2f newPos);

    void move(sf::Vector2f dir);
    void move(float x, float y);
};