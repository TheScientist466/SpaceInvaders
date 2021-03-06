#include "Headers/Global.h"

#include "Config/Config.h"

Global::Global(ObjectManager* _objMgr)
{
    gameWindow = new sf::RenderWindow(
        sf::VideoMode(Config::WindowConfig::windowDimentions.x, Config::WindowConfig::windowDimentions.y),
        Config::WindowConfig::windowTitle,
        sf::Style::Close
        );
    gameWindow->setFramerateLimit(60);

    backgroundTexture.loadFromFile(Paths::BackgroundImgPath);
    backgroundShape = sf::RectangleShape(static_cast<sf::Vector2f>(Config::WindowConfig::windowDimentions));
    backgroundShape.setTexture(&backgroundTexture);

    objManagerRef = _objMgr;
    objManagerRef->setAudioPlayer(&audPlayer);

    audioThread = new sf::Thread(&AudioPlayer::playBackgroundMusic, &audPlayer);
    audioThread->launch();
}

Global::~Global()
{
    audioThread->terminate();
    delete audioThread;
}


void Global::startLooping()
{
    while(gameWindow->isOpen())
    {
        while(gameWindow->pollEvent(gameEvents))
        {
            checkEvents();
        }
        Update();
    }
}

void Global::checkEvents()
{
    switch(gameEvents.type)
    {
        case sf::Event::Closed:
            gameWindow->close();
            return;
        case sf::Event::KeyPressed:
            objManagerRef->keyResponse(gameEvents.key.code, false);
            break;
        case sf::Event::KeyReleased:
            objManagerRef->keyResponse(gameEvents.key.code, true);
        default:
            break;
    }
}

void Global::Update()
{
    gameWindow->clear();
    gameWindow->draw(backgroundShape);

    for(auto& l : objManagerRef->lasers)
        gameWindow->draw(l->getSprite());

    for(auto& enemy : objManagerRef->enemies)
        gameWindow->draw(enemy->getSprite());

    gameWindow->draw(objManagerRef->player.getSprite());

    gameWindow->display();
    objManagerRef->Update();
}
