#pragma once

#include "Object.h"
#include "Laser.h"
#include <vector>

class Enemy : public Object
{
public:
    Enemy(sf::Vector2f initPos);

public:
    bool isAlive = true;

public:
    void Update();
};