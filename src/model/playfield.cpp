//
// Created by farrukh on 2/01/25.
//

#include "playfield.hpp"


PlayField::PlayField(Point center, float w, float h, ModelColor frameColor,
             ModelColor fillColor):
        CollidableRectangle{center, w, h, frameColor,fillColor}
{}

bool PlayField::isCollidingWithCircle(Point centerCircle, float r){
  return CollidableRectangle::isCollidingWithCircle(centerCircle,r);
}

