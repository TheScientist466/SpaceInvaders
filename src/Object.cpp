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


