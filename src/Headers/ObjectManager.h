#pragma once

#include <vector>

#include "Player.h"
#include "Laser.h"

class ObjectManager {

public:
    ObjectManager();

private:


public:
    Player player;
    sf::Vector2f playerDir;
    std::vector<Laser*> lasers;

private:
    void PlayerMovement(sf::Keyboard::Key k, bool inv);

public:
    void Update();
    void keyResponse(sf::Keyboard::Key k, bool keyReleased);



};