#pragma once

#include "Object.h"

class Laser : public Object
{

public:
    Laser();

public:
    sf::Vector2f direction;
};