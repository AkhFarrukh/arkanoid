//
// Created by farrukh on 31/12/24.
//

#include "view.hpp"


View::View(Canvas& canvas)
            : canvas_{canvas},
            drawables_{canvas.getVectorOfDrawables()}
            {}



ALLEGRO_COLOR View::pickColorFromPalette(const ModelColor modelColor){
  switch (modelColor) {
    case FRAME_COLOR:
      return COLOR_BLACK;
    case BALL_COLOR:
      return COLOR_RED;
    case RACKET_COLOR:
      return COLOR_BLUE;
    case BRICK_COLOR:
      return COLOR_WHITE;
    case PLAYFIELD_COLOR:
      return COLOR_GREY;
    default:
      return COLOR_MAGENTA;
  }
}

void View::draw(){
  canvas_.update();//todo
  for(const auto& drawable : drawables_){
    shared_ptr<Rectangle> rectangle = dynamic_pointer_cast<Rectangle>(drawable);
    if(rectangle){
      const RectangleInfo info = rectangle->getRectangleInfo();
      const Point center = info.center;
      const float w = info.w;
      const float h = info.h;

      ALLEGRO_COLOR frameColor = pickColorFromPalette(info.frameColor);
      ALLEGRO_COLOR fillColor = pickColorFromPalette(info.fillColor);

      const float x1 = center.x - w / 2;
      const float x2 = center.x + w / 2;
      const float y1 = center.y - h / 2;
      const float y2 = center.y + h / 2;
      al_draw_filled_rectangle(x1, y1, x2, y2, fillColor);
      al_draw_rectangle(x1, y1, x2, y2, frameColor, 1);
    }
    shared_ptr<Circle> circle = dynamic_pointer_cast<Circle>(drawable);
    if(circle) {
      const CircleInfo info = circle->getCircleInfo();
      const Point center = info.center;
      const float r = info.r;

      ALLEGRO_COLOR frameColor = pickColorFromPalette(info.frameColor);
      ALLEGRO_COLOR fillColor = pickColorFromPalette(info.fillColor);

      al_draw_filled_circle(center.x, center.y, r, fillColor);
      al_draw_circle(center.x, center.y, r, frameColor, 1);
    }

  }
}
