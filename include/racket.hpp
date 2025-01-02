//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_RACKET_HPP
#define ARKANOID_RACKET_HPP



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
    const float movementSpeed = 8.0F;
    Point tempCenter;

public:
    Racket(Point center, float w, float h, ModelColor frameColor,
           ModelColor fillColor);

    void update();
    void moveLeft();
    void moveRight();
    float getAngle(Point collisionPoint);
};


#endif //ARKANOID_RACKET_HPP
