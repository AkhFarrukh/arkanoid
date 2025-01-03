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
--------------------------------------------------*/
class Racket : public CollidableRectangle{
    const float movementSpeed = gameSpeed;
    Point tempCenter;
    const float racketLeftLimit;
    const float racketRightLimit;

public:
    Racket(Point center, float w, float h, ModelColor frameColor,
           ModelColor fillColor, const float racketLeftLimit, const float racketRightLimit);

    void update();
    void moveLeft();
    void moveRight();
    float getAngle(Point collisionPoint);

    float getWidth();

    float getHeight();
};


#endif //ARKANOID_RACKET_HPP
