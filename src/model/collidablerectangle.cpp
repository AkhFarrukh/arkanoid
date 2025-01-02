//
// Created by farrukh on 1/01/25.
//

#include "collidablerectangle.hpp"

CollidableRectangle::CollidableRectangle(Point center, float w, float h,
        ModelColor frameColor, ModelColor fillColor):
        Rectangle{center, w, h, frameColor,fillColor} {}


float CollidableRectangle::getDistance(Point p1, Point p2) {
  float distanceX = p1.x - p2.x;
  float distanceY = p1.y - p2.y;
  float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
  return distance;
}


bool CollidableRectangle::isPointOnLine(Point l1, Point l2, Point p, float len) {
  float distance1 = getDistance(p,l1);
  float distance2 = getDistance(p,l2);

  float bufferCollisionPrecision = 0.001; //todo make global
  if(distance1 + distance2 >= len-bufferCollisionPrecision and
     distance1 + distance2 <= len+bufferCollisionPrecision){
    return true;
  }
  return false;
}


bool CollidableRectangle::checkCollisionCircleLine(
        Point l1, Point l2, Point centerCircle, float r, float len) {
  float dot = (((centerCircle.x - l1.x) * (l2.x - l1.x) ) +
               ((centerCircle.y - l1.y) * (l2.y - l1.y) ) ) / pow(len, 2);

  Point closest{l1.x + (dot * (l2.x - l1.x)), l1.y + (dot * (l2.y - l1.y))};

  if(!isPointOnLine(l1, l2, closest, len)){
    return false;
  }
  if(getDistance(closest,centerCircle) <= r){
    return true;
  }
  return false;
}

CollisionType
CollidableRectangle::getCollidingEdgeType(Point center, float r) {
  //https://www.jeffreythompson.org/collision-detection/line-circle.php
  float x1 = center_.x - w_ / 2;
  float x2 = center_.x + w_ / 2;
  float y1 = center_.y - h_ / 2;
  float y2 = center_.y + h_ / 2;

  //bottom edge
  if (checkCollisionCircleLine(Point{x1, y2}, Point{x2, y2}, center, r, w_)){
    return  BOTTOM_EDGE_COLLISION;
  }
  //top edge
  if (checkCollisionCircleLine(Point{x1, y1}, Point{x2, y1}, center, r, w_)){
    return TOP_EDGE_COLLISION;
  }
  //left edge
  if (checkCollisionCircleLine(Point{x1, y1}, Point{x1, y2}, center, r, h_)){
    return LEFT_EDGE_COLLISION;
  }
  //right edge
  if(checkCollisionCircleLine(Point{x2, y1}, Point{x2, y2}, center, r, h_)){
    return RIGHT_EDGE_COLLISION;
  }
  return NO_COLLISION;
}


bool CollidableRectangle::isCollidingWithCircle(Point centerCircle, float r) {
  //https://www.jeffreythompson.org/collision-detection/circle-rect.php
  Point test = centerCircle;
  float x1 = center_.x - w_ / 2;
  float x2 = center_.x + w_ / 2;
  float y1 = center_.y - h_ / 2;
  float y2 = center_.y + h_ / 2;

  if(centerCircle.x < x1)      { test.x = x1; }
  else if(centerCircle.x > x2) { test.x = x2; }

  if(centerCircle.y < y1)      { test.y = y1; }
  else if(centerCircle.y > y2) { test.y = y2;}

  if(getDistance(centerCircle,test) <= r){ return true; }
  return false;
}





