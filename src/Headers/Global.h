#pragma once

#include <SFML/Graphics.hpp>

#include "ObjectManager.h"
#include "AudioPlayer.h"

class Global
{
public:
    //Constructor
    Global(ObjectManager* objectManager);
    ~Global();

private:
    //Private members
    sf::RenderWindow* gameWindow;
    sf::Event gameEvents;

    AudioPlayer audPlayer;
    sf::Thread* audioThread;

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