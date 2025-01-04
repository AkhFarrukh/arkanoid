//
// Created by farrukh on 2/01/25.
//

#ifndef ARKANOID_BRICK_HPP
#define ARKANOID_BRICK_HPP

#include <iostream>

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "rectangle.hpp"
#include "collidablerectangle.hpp"

using namespace std;
/*------------------------------------------------------------------------
  Brick.
  This is a class for bricks that can be broken by colliding with a circle
 ------------------------------------------------------------------------*/
class Brick : public CollidableRectangle{
  bool broken = false;
public:
    Brick(Point center, float w, float h, ModelColor frameColor, ModelColor fillColor);
    bool isBroken();
    void brakeBrick(); // sets broken to true
    bool isCollidingWithCircle(Point centerCircle, float r);
    //Brakes on collision, and if already broken returns false to allow ball pass through it
};


#endif //ARKANOID_BRICK_HPP
