#pragma once

#include <vector>

#include "Player.h"
#include "Laser.h"
#include "Enemy.h"
#include "AudioPlayer.h"
#include "Spawner.h"

class ObjectManager {

public:
    ObjectManager();

private:
    bool playerCanShoot;
    unsigned int score = 0, laserShot = 0;
    AudioPlayer* audPlayerRef;
    Spawner spawner;

public:
    Player player;
    sf::Vector2f playerDir;
    std::vector<Laser*> lasers;
    std::vector<Enemy*> enemies;

private:
    void PlayerMovement(sf::Keyboard::Key k, bool inv);
    void EnemyLaserHitChecker();

public:
    void Update();
    void keyResponse(sf::Keyboard::Key k, bool keyReleased);
    void setAudioPlayer(AudioPlayer* aud);
};