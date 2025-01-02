//
// Created by farrukh on 2/01/25.
//

#ifndef ARKANOID_PLAYFIELD_HPP
#define ARKANOID_PLAYFIELD_HPP


#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "rectangle.hpp"
#include "collidablerectangle.hpp"

class PlayField: public CollidableRectangle{
public:
    PlayField(Point center, float w, float h,
              ModelColor frameColor, ModelColor fillColor);

    bool isCollidingWithCircle(Point centerCircle, float r);

};


#endif //ARKANOID_PLAYFIELD_HPP
