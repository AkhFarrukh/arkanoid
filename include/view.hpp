//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_VIEW_HPP
#define ARKANOID_VIEW_HPP

#include "canvas.hpp"
#include "drawable.hpp"
#include "modelcolor.hpp"
#include "brick.hpp"

using namespace std;

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
  vector<shared_ptr<Drawable>> drawables_ {};

  const float topTextAlignmentY = 10.0F;
  const float livesCountTextX = windowWidth - 100.0f;
  const float scoreCountX = 100.0F;

  const float endMessageX = windowWidth /2.0F;
  const float endMessageY = windowHeight /2.0F;
  ALLEGRO_FONT *font;

  ALLEGRO_COLOR pickColorFromPalette(ModelColor modelColor);
public:
  View(Canvas& canvas, ALLEGRO_FONT *font);


  View& operator=(View&& other) noexcept;

  void draw();

    void draw(shared_ptr<Rectangle> rectangle);

    void draw(shared_ptr<Circle> circle);

    void drawEndMessage(const string& message, const string& key);
};


#endif //ARKANOID_VIEW_HPP
