//
// Created by farrukh on 31/12/24.
//

#include "view.hpp"


View::View(Canvas& canvas, ALLEGRO_FONT *font)
            : canvas_{canvas},
            drawables_{canvas.getVectorOfDrawables()},
            font{font}
            {}


View& View::operator=(View&& other) noexcept{
  if (this != &other) {
    canvas_ = move(other.canvas_);
    drawables_ = move(other.drawables_);
  }
  return *this;
}



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


void View::draw(shared_ptr<Rectangle>rectangle){
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

void View::draw(shared_ptr<Circle> circle){
  const CircleInfo info = circle->getCircleInfo();
  const Point center = info.center;
  const float r = info.r;

  ALLEGRO_COLOR frameColor = pickColorFromPalette(info.frameColor);
  ALLEGRO_COLOR fillColor = pickColorFromPalette(info.fillColor);

  al_draw_filled_circle(center.x, center.y, r, fillColor);
  al_draw_circle(center.x, center.y, r, frameColor, 1);
}


void View::drawEndMessage(const string& message, const string& key){
  ALLEGRO_COLOR textColor = pickColorFromPalette(FRAME_COLOR);
  auto verticalCenterAdjustment =
          static_cast<float>(al_get_font_line_height(font) / 2.0);
  al_draw_text(font, textColor, endMessageX, endMessageY- verticalCenterAdjustment,
               ALLEGRO_ALIGN_CENTRE, message.c_str());
  al_draw_text(font, textColor, endMessageX, endMessageY + 25.0F - verticalCenterAdjustment,
               ALLEGRO_ALIGN_CENTRE,
               ("Score :" + to_string(canvas_.getScore())).c_str());
  al_draw_text(font, textColor, endMessageX, endMessageY +50.0F- verticalCenterAdjustment,
               ALLEGRO_ALIGN_CENTRE, ("press " + key +" to restart").c_str());
}


void View::draw(){
  canvas_.update();//todo
  for(const auto& drawable : drawables_){
    shared_ptr<Rectangle> rectangle = dynamic_pointer_cast<Rectangle>(drawable);
    if(rectangle){
      shared_ptr<Brick> brick = dynamic_pointer_cast<Brick>(rectangle);
      if(brick){
        if(!brick->isBroken()){
          draw(rectangle);
        }
      } else {
        draw(rectangle);
      }
    }
    shared_ptr<Circle> circle = dynamic_pointer_cast<Circle>(drawable);
    if(circle) {
      draw(circle);
    }
  }



  ALLEGRO_COLOR textColor = pickColorFromPalette(FRAME_COLOR);
  auto verticalCenterAdjustment =
          static_cast<float>(al_get_font_line_height(font) / 2.0);
  al_draw_text(font, textColor, livesCountTextX, topTextAlignmentY- verticalCenterAdjustment,
               ALLEGRO_ALIGN_CENTRE,
               ("Extra Lives :"+to_string(canvas_.getExtraLivesNumber())).c_str());
  al_draw_text(font, textColor, scoreCountX, topTextAlignmentY- verticalCenterAdjustment,
               ALLEGRO_ALIGN_CENTRE,
               ("Score :" + to_string(canvas_.getScore())).c_str());

  if(canvas_.isGameOver()){
    drawEndMessage("Game Over", "R");
  }
  if(canvas_.isGameWon()){
    drawEndMessage("You Win !", "any");
  }
}

