//
// Created by farrukh on 31/12/24.
//


#include "text.hpp"


void Text::draw() {
  auto verticalCenterAdjustment =
          static_cast<float>(al_get_font_line_height(font) / 2.0);
  al_draw_text(font, color_, center_.x, center_.y - verticalCenterAdjustment,
               ALLEGRO_ALIGN_CENTRE, s_.c_str());
}

bool Text::contains(Point p) const {
  auto w=al_get_font_line_height(font);
  auto h=al_get_text_width(font,s_.c_str());
  auto verticalCenterAdjustment =
          static_cast<float>(al_get_font_line_height(font) / 2.0);
  return abs(p.x-center_.x)<=w && abs(p.y-(center_.y - verticalCenterAdjustment))<=h;

}