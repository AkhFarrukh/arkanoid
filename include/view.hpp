//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_VIEW_HPP
#define ARKANOID_VIEW_HPP

#include "canvas.hpp"
#include "drawable.hpp"
#include "modelcolor.hpp"
#include "brick.hpp"

const ALLEGRO_COLOR COLOR_RED     = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR COLOR_GREY    = al_map_rgb(200, 200, 200);
const ALLEGRO_COLOR COLOR_GREEN   = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR COLOR_YELLOW  = al_map_rgb(255, 255, 0);
const ALLEGRO_COLOR COLOR_BLACK   = al_map_rgb(0, 0, 0);
const ALLEGRO_COLOR COLOR_WHITE   = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR COLOR_PINK    = al_map_rgb(200, 150, 167);
const ALLEGRO_COLOR COLOR_MAGENTA = al_map_rgb(255, 0, 255);
const ALLEGRO_COLOR COLOR_BLUE    = al_map_rgb(0, 0, 255);

class View {
  Canvas canvas_;
  const vector<shared_ptr<Drawable>> drawables_ {};

  ALLEGRO_COLOR pickColorFromPalette(ModelColor modelColor);
public:
  View(Canvas& canvas);
  void draw();

    void draw(shared_ptr<Rectangle> rectangle);

    void draw(shared_ptr<Circle> circle);
};


#endif //ARKANOID_VIEW_HPP
