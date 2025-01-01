//
// Created by farrukh on 31/12/24.
//


#include "text.hpp"


bool Text::contains(Point p) const {
  auto w=al_get_font_line_height(font);
  auto h=al_get_text_width(font,s_.c_str());
  auto verticalCenterAdjustment =
          static_cast<float>(al_get_font_line_height(font) / 2.0);
  return abs(p.x-center_.x)<=w && abs(p.y-(center_.y - verticalCenterAdjustment))<=h;

}