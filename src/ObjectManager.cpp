#include "Headers/ObjectManager.h"
#include "Headers/AudioPlayer.h"
#include "Config/Config.h"

static float clamp(float val, float lo, float hi)
{
    if(val < lo)
        return lo;
    
    if(val > hi)
        return hi;

    return val;
}

ObjectManager::ObjectManager()
{
    playerDir = sf::Vector2f(0, 0);
    playerCanShoot = true;

    srand(time(0));

    spawner = Spawner(&enemies);
}

void ObjectManager::keyResponse(sf::Keyboard::Key k, bool _keyReleased)
{
    if(k == sf::Keyboard::W || k == sf::Keyboard::A || k == sf::Keyboard::S ||k == sf::Keyboard::D)
    {
        PlayerMovement(k, _keyReleased);
    }

    if(k == sf::Keyboard::Space)
    {
        if(!_keyReleased)
        {
            if (playerCanShoot)
            {
                Laser* l = new Laser(player.getPosition() + Config::Player::LaserOffset);
                lasers.push_back(l);
                playerCanShoot = false;
                audPlayerRef->playLaserSound();
            }
        }
        else
            playerCanShoot = true;
    }
}

void ObjectManager::setAudioPlayer(AudioPlayer* aud)
{
    audPlayerRef = aud;
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

    playerDir = sf::Vector2f(clamp(playerDir.x, -1.f, 1.f), clamp(playerDir.y, -1.f, 1.f));
}

void ObjectManager::EnemyLaserHitChecker()
{
    for(auto& l : lasers)
    {
        for(auto& e : enemies)
        {
            if(e->doesIntersect(*l) && e->isAlive)
            {
                e->isAlive = false;
                l->isAlive = false;
                audPlayerRef->playExplosionSound();
            }
        }
    }
}

void ObjectManager::Update()
{
    player.move(playerDir);
    spawner.update();

    EnemyLaserHitChecker();

    for(int i = 0; i < enemies.size(); i++)
    {
        if(!enemies[i]->isAlive)
        {
            delete enemies[i];
            enemies.erase(enemies.begin()+i);
        }
        else enemies[i]->Update();
    }

    for(int i = 0; i < lasers.size(); i++)
    {
        if(lasers[i]->getPosition().y < -150 || !lasers[i]->isAlive)
        {
            delete lasers[i];
            lasers.erase(lasers.begin() + i);
        }
        else lasers[i]->update();
    }
}