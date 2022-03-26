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
    sf::Vector2f hitBox;

public:
    float moveSpeed = 0.f;

    bool isAlive = true;

public:
    sf::Sprite getSprite() const;

    void setObjectTexture(const char* path);
    void setObjectTexture(const char* path, sf::IntRect r);

    void setObjectSpriteSize(sf::Vector2u size);

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f newPos);

    void move(sf::Vector2f dir);
    void move(float x, float y);

    bool doesIntersect(Object& other) const;
};