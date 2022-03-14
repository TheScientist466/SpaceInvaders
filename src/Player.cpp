#include "Headers/Player.h"
#include "Headers/VectorMath.h"

#include "Config/Config.h"

Player::Player()
{
    speed = Config::Player::Speed;

    setObjectTexture(Paths::PlayerImgPath);

    setObjectSpriteSize(Config::Player::TextureSize);

    objectSprite.setOrigin(objectTexture->getSize().x / 2, objectTexture->getSize().y);

    setPosition(Config::Player::InitPos);
}

void Player::setPosition(sf::Vector2f _newPos)
{
    position = _newPos;
    objectSprite.setPosition(_newPos);
}

void Player::move(sf::Vector2f _dir)
{
    sf::Vector2f offset = _dir * speed;
    sf::Vector2f pos = sf::Vector2f(offset.x + position.x, offset.y + position.y);
    setPosition(pos);
}

void Player::move(float x, float y)
{
    move(sf::Vector2f(x, y));
}




