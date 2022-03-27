#include "Headers/Enemy.h"

#include "Config/Config.h"

Enemy::Enemy(sf::Vector2f _initPos)
{
    moveSpeed = rand() % 21 + 15;
    moveSpeed /= 10.f;

    setObjectTexture(Paths::EnemySprite);
    setObjectSpriteSize(Config::Enemy::TextureSize);

    objectSprite.setOrigin(sf::Vector2f(objectTexture->getSize().x / 2, 0) + Config::Enemy::OriginOffset);
    setPosition(_initPos);

    hitBox = Config::Enemy::HitboxSize;
}

void Enemy::Update()
{
    move(0, 1);

    if(position.y > Config::WindowConfig::windowDimentions.y + 50)
        setPosition(sf::Vector2f(position.x, -100));
}
