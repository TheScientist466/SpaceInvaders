#pragma once

#include <SFML/Graphics.hpp>

#include "ObjectManager.h"

class Global
{
public:
    //Constructor
    Global(ObjectManager* objectManager);

private:
    //Private members
    sf::RenderWindow* gameWindow;
    sf::Event gameEvents;

    sf::RectangleShape backgroundShape;
    sf::Texture backgroundTexture;

    ObjectManager* objManagerRef;

public:
    //Public methods
    void startLooping();

private:
    //Private methods
    void checkEvents();
    void Update();

};