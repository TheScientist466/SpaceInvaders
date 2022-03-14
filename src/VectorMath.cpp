#include "Headers/VectorMath.h"
#include <cmath>

sf::Vector2f VectorMath::normalize(sf::Vector2f _vec)
{
    return (_vec / sqrtf(powf(_vec.x, 2) + powf(_vec.y, 2)));
}