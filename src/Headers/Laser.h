#pragma once

#include "Object.h"

class Laser : public Object
{

public:
    Laser(sf::Vector2f firePosition, sf::Vector2f dir = sf::Vector2f(0, -1));

public:
    sf::Vector2f direction;

public:
    void update();
};