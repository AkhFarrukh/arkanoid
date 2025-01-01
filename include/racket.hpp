//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_RACKET_HPP
#define ARKANOID_RACKET_HPP



#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "rectangle.hpp"

using namespace std;


/*--------------------------------------------------
Racket class
--------------------------------------------------*/
class Racket : public virtual Rectangle{
    const float movementSpeed = 8.0F;

public:
    Racket(Point center, float w, float h, ModelColor frameColor,
           ModelColor fillColor);
    void draw() override;

    void moveLeft();
    void moveRight();
    float getAngle(Point collisionPoint);
};


#endif //ARKANOID_RACKET_HPP
