//
// Created by farrukh on 2/01/25.
//

#ifndef ARKANOID_BRICK_HPP
#define ARKANOID_BRICK_HPP

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "rectangle.hpp"
#include "collidablerectangle.hpp"

using namespace std;
class Brick : public CollidableRectangle{
  bool broken = false;
public:
    Brick(Point center, float w, float h, ModelColor frameColor,
      ModelColor fillColor);

    bool isBroken();
    void brakeBrick();
    bool isCollidingWithCircle(Point centerCircle, float r);

};


#endif //ARKANOID_BRICK_HPP
