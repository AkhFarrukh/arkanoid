//
// Created by farrukh on 31/12/24.
//

#include "canvas.hpp"

Canvas::Canvas(){
  drawables.push_back(
          make_shared<Racket>(Point{mid_x,mid_y+180}, 100.0F, 15.0F, COLOR_BLACK, COLOR_BLUE)
          );
  shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(drawables[0]);
  drawables.push_back(
          make_shared<BouncyBall>(Point{mid_x,mid_y}, 10.0F, COLOR_BLACK, COLOR_RED, racket)
          );

}

void Canvas::draw() {
  for (auto &c : drawables) {
    c->draw();
  }
}

shared_ptr<vector<shared_ptr<Drawable>>> getVectorOfDrawables(){

}

void Canvas::mouseClick(Point mouseLoc) {
}

bool Canvas::keyPressed(int keyCode) {
  shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(drawables[0]);
  switch (keyCode) {
    case ALLEGRO_KEY_Q:
      racket->moveLeft();
      break;
    case ALLEGRO_KEY_D:
      racket->moveRight();
      break;
    default: {
    }  // pass (normal)
  }
  return true;
}