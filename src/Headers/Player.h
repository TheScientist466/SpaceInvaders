#pragma once

#include <SFML/Graphics.hpp>

#include "Object.h"

class Player : public Object{

public:
    Player();
    ~Player();

private:
    sf::Texture* playerTexture;
    sf::Rect<float> playerHitbox;
    sf::Sprite playerSprite;

    sf::Vector2f position;

    float speed;

public:
    sf::Sprite* getSprite();
    sf::Rect<float> getHitbox();

    void setPosition(sf::Vector2f newPos);
    void move(sf::Vector2f direction);
    void move(float x, float y);
};