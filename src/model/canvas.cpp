//
// Created by farrukh on 31/12/24.
//

#include "canvas.hpp"

Canvas::Canvas(){
  const int   rows      = 14;
  const int   columns   = 8;

  const float playFieldWidth = windowWidth - 10.0F;
  const float playFieldHeight = windowHeight - 10.0F;

  const float cell_sizeX = playFieldWidth / rows; //todo camelcase
  const float cell_sizeY = (playFieldHeight * (1.0F / 3.0F)) / columns;
  //const float margin    = 10;
  const float offsetX    = cell_sizeX ; //+ margin
  const float offsetY    = cell_sizeY ;//+ margin

  const float startX = (windowWidth - playFieldWidth) / 2.0F;
  const float startY = (windowHeight - playFieldHeight) / 2.0F;



  shared_ptr<PlayField> playField = make_shared<PlayField>(
          Point{mid_x,mid_y}, playFieldWidth, playFieldHeight,
          FRAME_COLOR, PLAYFIELD_COLOR);


  drawables.push_back(playField);
  collidables.push_back(playField);

  shared_ptr<Racket> racket = make_shared<Racket>(
          Point{mid_x,mid_y+180}, 150.0F, 15.0F, FRAME_COLOR, RACKET_COLOR);
  drawables.push_back(racket);
  collidables.push_back(racket);


  for (const int y : views::iota(0, columns)) { //itoa is like range in python
    for (const int x : views::iota(0, rows)) {
      // emplace_back is like push_back but is used to construct a new
      // object directly in the vector. It avoids constructing and then
      // copying. You pass the parameters of the constructor directly
      // to emplace_back
      shared_ptr<Brick> brick = make_shared<Brick>(
              Point{startX + offsetX * static_cast<float>(x) + offsetX / 2,
                    startY + offsetY * static_cast<float>(y) + offsetY / 2},
                    cell_sizeX, cell_sizeY,
              FRAME_COLOR, BRICK_COLOR);

      drawables.push_back(brick);
      collidables.push_back(brick);
    }
  }
  //shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(drawables[0]);
  shared_ptr<BouncyBall> ball =make_shared<BouncyBall>(
          Point{mid_x,mid_y}, 5.0F, FRAME_COLOR, BALL_COLOR, collidables);
  drawables.push_back(ball);
}

void Canvas::update() {
  shared_ptr<BouncyBall> ball = dynamic_pointer_cast<BouncyBall>(drawables.back());
  shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(drawables[1]);
  ball->update();
  racket->update();
}

const vector<shared_ptr<Drawable>>& Canvas::getVectorOfDrawables() const{
  // constant reference
  return drawables;
}

void Canvas::mouseClick(Point mouseLoc) {
}

bool Canvas::keyPressed(int keyCode) {
  shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(drawables[1]);
  switch (keyCode) {
    case ALLEGRO_KEY_Q:
      racket->moveLeft();
      break;
    case ALLEGRO_KEY_D:
      racket->moveRight();
      break;
    default: {
    }  // pass (normal)
  }
  return true;
}