//
// Created by farrukh on 31/12/24.
//

#include "racket.hpp"

Racket::Racket(Point center, float w, float h, ModelColor frameColor,
               ModelColor fillColor) :
        CollidableRectangle(center, w, h, frameColor,fillColor),
        tempCenter{center}{}

void Racket::moveLeft() {
  tempCenter.x = center_.x - movementSpeed;
}

void Racket::moveRight() {
  tempCenter.x = center_.x + movementSpeed;
}



float Racket::getAngle(Point collisionPoint) {
  float leftEdgeX = center_.x - w_/2.0F;
  float x = collisionPoint.x - leftEdgeX;
  float L = w_;
  float alpha = 30.0F + 120.0F * (1 - x / L);
  alpha = alpha * PI / 180.0F;

  return alpha;
}

void Racket::update() {
  center_ = tempCenter;
}

