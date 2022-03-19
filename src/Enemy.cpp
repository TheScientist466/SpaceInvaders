#include "Headers/Enemy.h"

#include "Config/Config.h"

Enemy::Enemy(sf::Vector2f _initPos)
{
    moveSpeed = rand() % 21 + 15;
    moveSpeed /= 10.f;

    setObjectTexture(Paths::EnemySprite);
    setObjectSpriteSize(Config::Player::TextureSize);

    objectSprite.setOrigin(objectTexture->getSize().x / 2, 0);
    setPosition(_initPos);
}

void Enemy::Update()
{
    move(0, 1);

    if(position.y > Config::WindowConfig::windowDimentions.y)
        setPosition(sf::Vector2f(position.x, -100));
}
