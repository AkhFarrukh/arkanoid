//
// Created by farrukh on 31/12/24.
//

#include "racket.hpp"

Racket::Racket(Point center, float w, float h, ALLEGRO_COLOR frameColor,
               ALLEGRO_COLOR fillColor) : Rectangle(center, w, h, frameColor,
                                                    fillColor) {}

void Racket::moveLeft() {
  center_.x = center_.x - movementSpeed;
}

void Racket::moveRight() {
  center_.x = center_.x + movementSpeed;
}

void Racket::draw() {
  Rectangle::draw();
}