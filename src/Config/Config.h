#pragma once
#include "Paths.h"

#include <SFML/Graphics.hpp>

namespace Config
{
    namespace WindowConfig
    {
        static const sf::Vector2u windowDimentions  = sf::Vector2u(960U, 540U);
        static const char* windowTitle              = "Space Invaders";
    }

    namespace Player
    {
        static const sf::Vector2f Hitbox        = sf::Vector2f(100.f,   250.f);
        static const sf::Vector2f InitPos       = sf::Vector2f(480.f,   500.f);

        static const sf::Vector2u TextureSize   = sf::Vector2u(100, 100);

        static const float Speed                = 5.f;

        static const sf::Vector2f LaserOffset   = sf::Vector2f(0.f, -70.f);
    }

    namespace Laser
    {
        static const sf::Vector2u LaserSize     = sf::Vector2u(20, 20);
    }
}