#include "Headers/Player.h"
#include "Headers/VectorMath.h"

#include "Config/Config.h"

Player::Player()
{
    moveSpeed = Config::Player::Speed;

    setObjectTexture(Paths::PlayerImgPath);

    setObjectSpriteSize(Config::Player::TextureSize);

    objectSprite.setOrigin(objectTexture->getSize().x / 2, objectTexture->getSize().y);

    setPosition(Config::Player::InitPos);

    hitBox = Config::Player::Hitbox;
}




