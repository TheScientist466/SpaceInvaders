#include "Headers/Laser.h"

#include "Config/Config.h"

Laser::Laser(sf::Vector2f _pos, sf::Vector2f _dir)
{
    moveSpeed = 25.f;
    direction = _dir;

    setObjectTexture(Paths::LaserImgPath);

    setObjectSpriteSize(Config::Laser::LaserSize);

    objectSprite.setOrigin(objectTexture->getSize().x / 2, objectTexture->getSize().y / 2);

    setPosition(_pos);
}

void Laser::update()
{
    move(direction);
}