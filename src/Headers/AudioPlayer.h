#pragma once

#include <SFML/Audio.hpp>

class AudioPlayer
{
public:
    AudioPlayer();

private:
    sf::Music backgroundMusic;
    sf::Sound laserPlayer;
    sf::Sound explotionPlayer;

public:
    sf::SoundBuffer laserSound;
    sf::SoundBuffer explosionSound;

public:
    void playBackgroundMusic();
    void playLaserSound();
    void playExplosionSound();

};