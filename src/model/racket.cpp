//
// Created by farrukh on 31/12/24.
//

#include "racket.hpp"

Racket::Racket(Point center, float w, float h, ModelColor frameColor,
               ModelColor fillColor) : Rectangle(center, w, h, frameColor,
                                                    fillColor) {}

void Racket::moveLeft() {
  center_.x = center_.x - movementSpeed;
}

void Racket::moveRight() {
  center_.x = center_.x + movementSpeed;
}



float Racket::getAngle(Point collisionPoint) {
  float leftEdgeX = center_.x - w_/2.0F;
  float x = collisionPoint.x - leftEdgeX;
  float L = w_;
  float alpha = 30.0F + 120.0F * (1 - x / L);
  alpha = alpha * PI / 180.0F;

  return alpha;
}

void Racket::draw() {
  Rectangle::draw();
}
