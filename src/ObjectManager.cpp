#include "Headers/ObjectManager.h"

ObjectManager::ObjectManager()
{
    playerDir = sf::Vector2f(0, 0);
}

void ObjectManager::keyResponse(sf::Keyboard::Key k, bool _Released)
{
    if(k == sf::Keyboard::W || k == sf::Keyboard::A || k == sf::Keyboard::S ||k == sf::Keyboard::D)
    {
        PlayerMovement(k, _Released);
    }
}

void ObjectManager::PlayerMovement(sf::Keyboard::Key k, bool inv)
{
    if(!inv)
    {
        if (k == sf::Keyboard::S)
            playerDir = sf::Vector2f(playerDir.x, 1);
        else if (k == sf::Keyboard::W)
            playerDir = sf::Vector2f(playerDir.x, -1);

        if (k == sf::Keyboard::D)
            playerDir = sf::Vector2f(1, playerDir.y);
        else if (k == sf::Keyboard::A)
            playerDir = sf::Vector2f(-1, playerDir.y);
    }
    else
    {
        if (k == sf::Keyboard::S)
            playerDir = sf::Vector2f(playerDir.x, 0);
        else if (k == sf::Keyboard::W)
            playerDir = sf::Vector2f(playerDir.x, 0);

        if (k == sf::Keyboard::D)
            playerDir = sf::Vector2f(0, playerDir.y);
        else if (k == sf::Keyboard::A)
            playerDir = sf::Vector2f(0, playerDir.y);
    }
}

void ObjectManager::Update()
{
    player.move(playerDir);
}