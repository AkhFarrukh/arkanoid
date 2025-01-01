//
// Created by farrukh on 1/01/25.
//

#ifndef ARKANOID_COLLIDABLERECTANGLE_HPP
#define ARKANOID_COLLIDABLERECTANGLE_HPP

#include <cmath>

#include "rectangle.hpp"
#include "point.hpp"


enum CollisionType{
    NO_COLLISION,
    LEFT_EDGE_COLLISION,
    RIGHT_EDGE_COLLISION,
    TOP_EDGE_COLLISION,
    BOTTOM_EDGE_COLLISION
};

/*------------------------------------------------------------------------
 * https://www.jeffreythompson.org/collision-detection/circle-rect.php
 ------------------------------------------------------------------------*/
class CollidableRectangle : public virtual Rectangle{
private:

    bool checkCollisionCircleLine(
            Point p1, Point p2, Point centerCircle, float r, float len);
public:
    CollidableRectangle(Point center, float w, float h,
            ModelColor frameColor,
            ModelColor fillColor);

    bool isCollidingWithCircle(Point centerCircle, float r);

    CollisionType getCollidingEdgeType(Point center, float r);

};


#endif //ARKANOID_COLLIDABLERECTANGLE_HPP
