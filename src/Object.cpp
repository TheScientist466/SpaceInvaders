#include "Headers/Object.h"

Object::Object()
{
    objectTexture = new sf::Texture();
    objectSprite = sf::Sprite();
}

Object::~Object() {
    delete objectTexture;
}

sf::Sprite Object::getSprite() const
{
    return objectSprite;
}

void Object::setObjectTexture(const char* path)
{
    objectTexture->loadFromFile(path);
    objectTexture->setSmooth(true);
    objectSprite.setTexture(*objectTexture);
}

void Object::setObjectTexture(const char* path, sf::IntRect r)
{
    objectTexture->loadFromFile(path, r);
    objectTexture->setSmooth(true);
    objectSprite.setTexture(*objectTexture);
}

void Object::setObjectSpriteSize(sf::Vector2u size)
{
    sf::Vector2f textureScale;
    textureScale = sf::Vector2f(size.x / (float) objectTexture->getSize().x,
                                size.y / (float) objectTexture->getSize().y);
    objectSprite.setScale(textureScale);
}

sf::Vector2f Object::getPosition() const
{
    return position;
}

void Object::setPosition(sf::Vector2f _newPos)
{
    position = _newPos;
    objectSprite.setPosition(_newPos);
}

void Object::move(sf::Vector2f _dir)
{
    sf::Vector2f offset = _dir * moveSpeed;
    sf::Vector2f pos = sf::Vector2f(offset.x + position.x, offset.y + position.y);
    setPosition(pos);
}

void Object::move(float x, float y)
{
    move(sf::Vector2f(x, y));
}
