
#include "canvas.hpp"

Canvas::Canvas(){
  const float windowMargin = 5.0F;
  const float playFieldOffsetY = 20.0F;

  const float playFieldWidth = windowWidth - 2.0F * windowMargin;
  const float playFieldHeight = windowHeight - 2.0F * windowMargin - 2.0F * playFieldOffsetY;

  const float margin    = 1.5F;
  const float cell_sizeX = playFieldWidth / rows - margin;
  const float cell_sizeY = (playFieldHeight * (1.0F / 3.0F)) / columns - margin;

  const float offsetX    = cell_sizeX + margin;
  const float offsetY    = cell_sizeY + margin;

  const float startX = (windowWidth - playFieldWidth) / 2.0F ;
  const float startY = (windowHeight - playFieldHeight) / 2.0F + 2.0F * playFieldOffsetY;

  const float playFieldMidX = mid_x;
  const float playFieldMidY = mid_y + playFieldOffsetY;

  const float racketWidth = 2.0F *(cell_sizeX + margin);
  const float racketHeight = cell_sizeY / 1.5F;

  const float racketPosX = playFieldMidX;
  const float racketPosY = playFieldHeight;

  const float racketLeftLimit = playFieldMidX - playFieldWidth / 2.0F + racketWidth /2.0F;
  const float racketRightLimit = playFieldMidX + playFieldWidth / 2.0F - racketWidth /2.0F;

  const float ballRadius = racketHeight / 3.0F;

  const float ballPosX = racketPosX + (racketWidth / 2.0F) / 3.0F ;
  const float ballPosY = racketPosY - ballRadius - racketHeight / 2.0F + 1;

  shared_ptr<CollidableRectangle> playField = make_shared<CollidableRectangle>(
          Point{playFieldMidX,playFieldMidY}, playFieldWidth, playFieldHeight,
          FRAME_COLOR, PLAYFIELD_COLOR);


  drawables.push_back(playField);
  collidables.push_back(playField);

  racket = make_shared<Racket>(
          Point{racketPosX,racketPosY}, racketWidth, racketHeight,
          FRAME_COLOR, RACKET_COLOR,
          racketLeftLimit, racketRightLimit);
  drawables.push_back(racket);
  collidables.push_back(racket);


  for (const int y : views::iota(0, columns)) {
    for (const int x : views::iota(0, rows)) {
      shared_ptr<Brick> brick = make_shared<Brick>(
              Point{startX + offsetX * static_cast<float>(x) + offsetX / 2,
                    startY + offsetY * static_cast<float>(y) + offsetY / 2},
                    cell_sizeX, cell_sizeY,
              FRAME_COLOR, BRICK_COLOR);

      drawables.push_back(brick);
      collidables.push_back(brick);
    }
  }
  ball =make_shared<BouncyBall>(
          Point{ballPosX,ballPosY}, ballRadius, FRAME_COLOR, BALL_COLOR, collidables);
  drawables.push_back(ball);

}

void Canvas::update() {
  ball->update();
}

int Canvas::getExtraLivesNumber(){
  int lives =ball->getExtraLivesNumber();
  if(lives <0){
    return 0;
  }
  return ball->getExtraLivesNumber();
}

const vector<shared_ptr<Drawable>>& Canvas::getVectorOfDrawables() const{
  return drawables;
}


bool Canvas::keyPressed(ModelInteractions keyCode) {
  switch (keyCode) {
    case MODEL_LEFT:{
      if(!ball->isGameOver()){
        racket->moveLeft();
        ball->moveWithRacket();
      }
      break;
    }
    case MODEL_RIGHT:{
      if (!ball->isGameOver()){
        racket->moveRight();
        ball->moveWithRacket();
        break;
      }
    }
    default: {
    }  // pass (normal)
  }
  return true;
}

int Canvas::getScore() {
  return ball->getScore();
}

bool Canvas::isGameOver() {
  return  ball->isGameOver();
}

bool Canvas::isGameWon() {
  return  ball->isGameWon();
}
