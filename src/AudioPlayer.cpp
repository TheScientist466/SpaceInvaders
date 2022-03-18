#include "Headers/AudioPlayer.h"

#include "Config/Config.h"

AudioPlayer::AudioPlayer()
{
    backgroundMusic.openFromFile(Paths::BackgoundAudio);
    backgroundMusic.setLoop(true);

    laserSound.loadFromFile(Paths::LaserAudio);
}

void AudioPlayer::playBackgroundMusic()
{
    backgroundMusic.play();
}

void AudioPlayer::playSound(sf::SoundBuffer &s)
{
    soundPlayer.setBuffer(s);
    soundPlayer.play();
}
