#include "Headers/Player.h"
#include "Headers/VectorMath.h"

#include "Config/Config.h"

Player::Player()
{
    moveSpeed = Config::Player::Speed;

    setObjectTexture(Paths::PlayerImgPath);

    setObjectSpriteSize(Config::Player::TextureSize);

    objectSprite.setOrigin(objectTexture->getSize().x / 2, objectTexture->getSize().y);

    setPosition(sf::Vector2f(Config::WindowConfig::windowDimentions.x / 2, Config::Player::InitPos.y));

    hitBox = Config::Player::Hitbox;
}




