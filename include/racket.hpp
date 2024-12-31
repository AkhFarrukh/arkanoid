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
    Racket(Point center, float w, float h, ALLEGRO_COLOR frameColor,
           ALLEGRO_COLOR fillColor);

    void moveLeft();
    void moveRight();
    void draw() override;
    float getAngle(Point collisionPoint);
};


#endif //ARKANOID_RACKET_HPP
