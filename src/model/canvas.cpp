//
// Created by farrukh on 31/12/24.
//

#include "canvas.hpp"

Canvas::Canvas(){
  drawables.push_back(
          make_shared<Racket>(Point{mid_x,mid_y+180}, 150.0F, 15.0F, FRAME_COLOR, RACKET_COLOR)
          );
  shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(drawables[0]);
  drawables.push_back(
          make_shared<BouncyBall>(Point{mid_x,mid_y}, 10.0F, FRAME_COLOR, BALL_COLOR, racket)
          );

}

void Canvas::update() {
  shared_ptr<BouncyBall> ball = dynamic_pointer_cast<BouncyBall>(drawables[1]);
  ball->update();
}

const vector<shared_ptr<Drawable>>& Canvas::getVectorOfDrawables() const{
  // constant reference
  return drawables;
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