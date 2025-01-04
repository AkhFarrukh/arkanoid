//
// Created by farrukh on 31/12/24.
//

#include "racket.hpp"

Racket::Racket(Point center, float w, float h, ModelColor frameColor,
               ModelColor fillColor,
               const float racketLeftLimit, const float racketRightLimit) :
        CollidableRectangle(center, w, h, frameColor,fillColor),
        racketLeftLimit{racketLeftLimit},
        racketRightLimit{racketRightLimit}
{}

void Racket::moveLeft() {
  center_.x = clamp(center_.x - movementSpeed, racketLeftLimit, racketRightLimit);
}

void Racket::moveRight() {
  center_.x = clamp(center_.x + movementSpeed, racketLeftLimit, racketRightLimit);
}



float Racket::getAngle(Point collisionPoint) {
  float leftEdgeX = center_.x - w_/2.0F;
  float x = collisionPoint.x - leftEdgeX;
  float L = w_;
  float alpha = 30.0F + 120.0F * (1 - x / L);
  alpha = alpha * PI / 180.0F;

  return alpha;
}


float Racket::getWidth(){
  return w_;
}
float Racket::getHeight(){
  return h_;
}