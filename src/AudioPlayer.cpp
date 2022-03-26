#include "Headers/AudioPlayer.h"

#include "Config/Config.h"

AudioPlayer::AudioPlayer()
{
    backgroundMusic.openFromFile(Paths::BackgoundAudio);
    backgroundMusic.setLoop(true);

    laserSound.loadFromFile(Paths::LaserAudio);
    laserPlayer.setBuffer(laserSound);

    explosionSound.loadFromFile(Paths::ExplosionSound);
    explotionPlayer.setBuffer(explosionSound);
}

void AudioPlayer::playBackgroundMusic()
{
    backgroundMusic.play();
}

void AudioPlayer::playLaserSound()
{
    laserPlayer.play();
}

void AudioPlayer::playExplosionSound()
{
    explotionPlayer.play();
}
