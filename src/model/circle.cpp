//
// Created by farrukh on 31/12/24.
//

#include "circle.hpp"

/*--------------------------------------------------
Circle class.

Use to display a filled-in circle on the screen
with different colors for the fill and the border

It should have all the features you need and you
should not need to edit it.
--------------------------------------------------*/

Circle::Circle(Point center, float r, ALLEGRO_COLOR frameColor,
               ALLEGRO_COLOR fillColor) noexcept
        : center_{center}, r_{r}, frameColor_{frameColor}, fillColor_{fillColor} {}

void Circle::draw() {
  al_draw_filled_circle(center_.x, center_.y, r_, fillColor_);
  al_draw_circle(center_.x, center_.y, r_, frameColor_, 1);
}

void Circle::setFillColor(ALLEGRO_COLOR fillColor) { fillColor_ = fillColor; }

void Circle::setFrameColor(ALLEGRO_COLOR frameColor) {
  frameColor_ = frameColor;
}

Point Circle::getCenter() const { return center_; }

bool Circle::contains(Point p) const {
  return ((p.x - center_.x) * (p.x - center_.x) +
          (p.y - center_.y) * (p.y - center_.y) <=
          r_ * r_);
}

void Circle::setCenter(Point newCenter) { center_ = newCenter; }

