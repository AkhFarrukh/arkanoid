//
// Created by farrukh on 31/12/24.
//

#include "canvas.hpp"


//Canvas::Canvas() = default;

void Canvas::draw() {
  racket_.draw();
  bouncyBall_.draw();
}

void Canvas::mouseClick(Point mouseLoc) {
}

bool Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
    case ALLEGRO_KEY_Q:
      racket_.moveLeft();
      break;
    case ALLEGRO_KEY_D:
      racket_.moveRight();
      break;
    default: {
    }  // pass (normal)
  }
  return true;
}