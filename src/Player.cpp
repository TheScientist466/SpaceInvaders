#include "Headers/Player.h"
#include "Headers/VectorMath.h"

#include "Config/Config.h"

Player::Player()
{
    speed = Config::Player::Speed;

    playerTexture = new sf::Texture();
    playerTexture->loadFromFile(Paths::PlayerImgPath);
    playerTexture->setSmooth(true);
    playerSprite = sf::Sprite();
    playerSprite.setTexture(*playerTexture);

    sf::Vector2f textureScale;
    textureScale = sf::Vector2f(Config::Player::TextureSize.x / (float) playerTexture->getSize().x,
                                Config::Player::TextureSize.x / (float) playerTexture->getSize().y);
    playerSprite.setScale(textureScale);

    playerSprite.setOrigin(playerTexture->getSize().x / 2, playerTexture->getSize().y);

    setPosition(Config::Player::InitPos);
}

Player::~Player()
{
    delete(playerTexture);
}

sf::Sprite* Player::getSprite()
{
    return &playerSprite;
}

void Player::setPosition(sf::Vector2f _newPos)
{
    position = _newPos;
    playerSprite.setPosition(_newPos);
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




