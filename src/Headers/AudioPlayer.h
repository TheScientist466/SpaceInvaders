#pragma once

#include <SFML/Audio.hpp>

class AudioPlayer
{
public:
    AudioPlayer();

private:
    sf::Music backgroundMusic;
    sf::Sound soundPlayer;

public:
    sf::SoundBuffer laserSound;

public:
    void playBackgroundMusic();
    void playSound(sf::SoundBuffer& s);

};