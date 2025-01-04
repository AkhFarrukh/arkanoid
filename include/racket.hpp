//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_RACKET_HPP
#define ARKANOID_RACKET_HPP

#include <algorithm>

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "rectangle.hpp"
#include "collidablerectangle.hpp"

using namespace std;


/*--------------------------------------------------
Racket class
 Racket that can be moved on a horizontal axis with a constant speed in a range between defined limitations.
--------------------------------------------------*/
class Racket : public CollidableRectangle{
    const float movementSpeed = gameSpeed;
    const float racketLeftLimit;
    const float racketRightLimit;

public:
    Racket(Point center, float w, float h, ModelColor frameColor,
           ModelColor fillColor, const float racketLeftLimit, const float racketRightLimit);
    void moveLeft();
    void moveRight();
    float getAngle(Point collisionPoint); //returns an angle of reflection based on collision position.
    float getWidth();
    float getHeight();
};


#endif //ARKANOID_RACKET_HPP
