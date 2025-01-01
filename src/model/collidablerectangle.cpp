//
// Created by farrukh on 1/01/25.
//

#include "collidablerectangle.hpp"

CollidableRectangle::CollidableRectangle(Point center, float w, float h,
        ModelColor frameColor, ModelColor fillColor):
        Rectangle{center, w, h, frameColor,fillColor} {}

bool CollidableRectangle::checkCollisionCircleLine(
        Point p1, Point p2, Point centerCircle, float r, float len) {

  float dot = ( ( (centerCircle.x - p1.x) * (p2.x - p1.x) ) +
                ( (centerCircle.y - p1.y) * (p2.y - p1.y)) ) / pow(len, 2);




  return false;
}

CollisionType
CollidableRectangle::getCollidingEdgeType(Point center, float r) {
  //https://www.jeffreythompson.org/collision-detection/line-circle.php
  float x1 = center_.x - w_ / 2;
  float x2 = center_.x + w_ / 2;
  float y1 = center_.y - h_ / 2;
  float y2 = center_.y + h_ / 2;


  return LEFT_EDGE_COLLISION;
}

bool CollidableRectangle::isCollidingWithCircle(Point centerCircle, float r) {
  //https://www.jeffreythompson.org/collision-detection/circle-rect.php
  Point test;
  float x1 = center_.x - w_ / 2;
  float x2 = center_.x + w_ / 2;
  float y1 = center_.y - h_ / 2;
  float y2 = center_.y + h_ / 2;

  if(centerCircle.x < x1)      { test.x = x1; }
  else if(centerCircle.x > x2) { test.x = x2; }

  if(centerCircle.y < y1)      { test.y = y1; }
  else if(centerCircle.y > y2) { test.y = x2;}

  Point dist{centerCircle.x - test.x, centerCircle.y - test.y};
  float distance = sqrt( pow(dist.x, 2) + pow(dist.y, 2) );

  if(distance <= r){ return true; }
  return false;
}



