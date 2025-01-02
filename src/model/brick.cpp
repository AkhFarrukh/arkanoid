//
// Created by farrukh on 2/01/25.
//

#include "brick.hpp"

Brick::Brick(Point center, float w, float h, ModelColor frameColor,
              ModelColor fillColor):
        CollidableRectangle{center, w, h, frameColor,fillColor}
{}

bool Brick::isBroken(){
  return broken;
}

void Brick::brakeBrick() {
  broken = true;
}

bool Brick::isCollidingWithCircle(Point centerCircle, float r) {

  if(!isBroken()){
    bool collision = CollidableRectangle::isCollidingWithCircle(centerCircle, r);
    if(collision){
      brakeBrick();
    }
    return collision;
  }
  return false;
}