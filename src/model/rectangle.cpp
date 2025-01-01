//
// Created by farrukh on 31/12/24.
//

#include "rectangle.hpp"


Rectangle::Rectangle(Point center, float w, float h, ModelColor frameColor,
                     ModelColor fillColor) noexcept
        : Drawable {},
          center_{center},
          w_{w},
          h_{h},
          frameColor_{frameColor},
          fillColor_{fillColor} {}


void Rectangle::setFillColor(ModelColor fillColor) {
  fillColor_ = fillColor;
}

void Rectangle::setFrameColor(ModelColor frameColor) {
  frameColor_ = frameColor;
}

bool Rectangle::contains(Point point) const {
  return point.x >= center_.x - w_ / 2 && point.x < center_.x + w_ / 2 &&
         point.y >= center_.y - h_ / 2 && point.y < center_.y + h_ / 2;
}

Point Rectangle::getCenter() const { return center_; }

RectangleInfo Rectangle::getRectangleInfo() const{
  return RectangleInfo{center_,w_,h_, frameColor_, fillColor_};
}

void Rectangle::update() {

}
