

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
  CollidableRectangle.
  This is a class that can detect a collision with a circle and tell on which edge the collision took place.
  The collision detection logic is copied from this website:
  https://www.jeffreythompson.org/collision-detection/circle-rect.php
 ------------------------------------------------------------------------*/
class CollidableRectangle : public Rectangle{
private:
    bool checkCollisionCircleLine(
            Point l1, Point l2, Point centerCircle, float r, float len); //checks if there is collision between a circle and a line between two points
    float getDistance(Point p1, Point p2);                               // returns distance between two points
    bool isPointOnLine(Point l1, Point l2, Point p, float len);          //check if point p is on the line between points l1 and l2.

public:
    CollidableRectangle(Point center, float w, float h,
            ModelColor frameColor,
            ModelColor fillColor);
    virtual bool isCollidingWithCircle(Point centerCircle, float r) ;   //check,if there was a collision with a circle of given center and radius
    CollisionType getCollidingEdgeType(Point center, float r);          //returns the side on which the collision took place
};


#endif //ARKANOID_COLLIDABLERECTANGLE_HPP
