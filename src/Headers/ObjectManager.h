#pragma once

#include <vector>

#include "Player.h"
#include "Laser.h"

class ObjectManager {

public:
    ObjectManager();

private:
    std::vector<Laser> lasers;

public:
    Player player;
    sf::Vector2f playerDir;

private:
    void PlayerMovement(sf::Keyboard::Key k, bool inv);

public:
    void Update();
    void keyResponse(sf::Keyboard::Key k, bool keyReleased);



};