#include "Headers/ObjectManager.h"

#include "Config/Config.h"

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

    if(k == sf::Keyboard::Space && _Released)
    {
        Laser* l = new Laser(player.getPosition() + Config::Player::LaserOffset);
        lasers.push_back(l);
    }
}

void ObjectManager::PlayerMovement(sf::Keyboard::Key k, bool inv)
{
    float sign = !inv ? 1 : -1;

    if (k == sf::Keyboard::S)
        playerDir += sf::Vector2f(0, 1) * sign;
    else if (k == sf::Keyboard::W)
        playerDir += sf::Vector2f(0, -1) * sign;

    if (k == sf::Keyboard::D)
        playerDir += sf::Vector2f(1, 0) * sign;
    else if (k == sf::Keyboard::A)
        playerDir += sf::Vector2f(-1, 0) * sign;

    playerDir = sf::Vector2f(std::clamp(playerDir.x, -1.f, 1.f), std::clamp(playerDir.y, -1.f, 1.f));
}

void ObjectManager::Update()
{
    player.move(playerDir);

    for(int i = 0; i < lasers.size(); i++)
    {
        lasers[i]->update();
        if(lasers[i]->getPosition().y < -150)
        {
            delete(lasers[i]);
            lasers.erase(lasers.begin()+i);
        }
    }
}