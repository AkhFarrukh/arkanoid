//
// Created by farrukh on 31/12/24.
//

#include "rectangle.hpp"


Rectangle::Rectangle(Point center, float w, float h, ALLEGRO_COLOR frameColor,
                     ALLEGRO_COLOR fillColor) noexcept
        : Drawable {},
          center_{center},
          w_{w},
          h_{h},
          frameColor_{frameColor},
          fillColor_{fillColor} {}

void Rectangle::draw() {
  const float x1 = center_.x - w_ / 2;
  const float x2 = center_.x + w_ / 2;
  const float y1 = center_.y - h_ / 2;
  const float y2 = center_.y + h_ / 2;
  al_draw_filled_rectangle(x1, y1, x2, y2, fillColor_);
  al_draw_rectangle(x1, y1, x2, y2, frameColor_, 1);
}

void Rectangle::setFillColor(ALLEGRO_COLOR fillColor) {
  fillColor_ = fillColor;
}

void Rectangle::setFrameColor(ALLEGRO_COLOR frameColor) {
  frameColor_ = frameColor;
}

bool Rectangle::contains(Point point) const {
  return point.x >= center_.x - w_ / 2 && point.x < center_.x + w_ / 2 &&
         point.y >= center_.y - h_ / 2 && point.y < center_.y + h_ / 2;
}

Point Rectangle::getCenter() const { return center_; }
