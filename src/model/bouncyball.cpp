//
// Created by farrukh on 31/12/24.
//

#include "bouncyball.hpp"

#include <utility>



shared_ptr<Racket> BouncyBall::findRacket() {
  for (auto &collidable: collidables_) {
    shared_ptr<Racket> racketPtr = dynamic_pointer_cast<Racket>(collidable);
    if(racketPtr){
      return racketPtr;
    }
  }
}

BouncyBall::BouncyBall(Point center, float r, ModelColor frameColor,
                       ModelColor fillColor,
                       vector<shared_ptr<CollidableRectangle>>& collidables) noexcept :
        Circle{center, r, frameColor, fillColor},
        collidables_{collidables},
        initialBallPosY{center.y}
{
  racket = findRacket();
  gameOver = false;
  gameWon = false;
}


void BouncyBall::inverseXSpeed(){
  horizontalSpeed = -horizontalSpeed;
}

void BouncyBall::inverseYSpeed(){
  verticalSpeed = -verticalSpeed;
}

void BouncyBall::changeSpeedBasedOnRacketAngle(shared_ptr<Racket> racket, Point center){
  float angle = racket->getAngle(Point{center.x, center.y + r_});
  horizontalSpeed = cos(angle) * speed;
  verticalSpeed = -sin(angle) * speed;
}



void BouncyBall::defaultCollide(CollisionType edge){
  switch (edge) {
    case TOP_EDGE_COLLISION:
      inverseYSpeed();
      break;
    case BOTTOM_EDGE_COLLISION:
      inverseYSpeed();
      break;
    case LEFT_EDGE_COLLISION:
      inverseXSpeed();
      break;
    case RIGHT_EDGE_COLLISION:
      inverseXSpeed();
      break;
    case NO_COLLISION:
      break;
  }
}
void BouncyBall::racketCollide(CollisionType edge,shared_ptr<Racket> racket, Point center){
  switch (edge) {
    case TOP_EDGE_COLLISION:
      changeSpeedBasedOnRacketAngle(racket, center);
      break;
    default:{
    }
  }
}


void BouncyBall::collideWithEdge(shared_ptr<CollidableRectangle> collidable, Point center){
  CollisionType edge = collidable->getCollidingEdgeType(center, r_);
  shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(collidable);
  if(racket){
    racketCollide(edge,racket,center);
  }else{
    defaultCollide(edge);
  }

}

void BouncyBall::startGame(){
  gameGoing = true;
}

bool BouncyBall::isGameOver(){
  return gameOver;
};

bool BouncyBall::isGameWon(){
  return  gameWon;
}

void BouncyBall::stopGame(){
  gameGoing = false;
  racketStartedMoving = false;
  framesToStartCounter = timeBeforeGameStart * refreshPerSecond;
  extraLivesNumber--;
  if (getExtraLivesNumber() < 0){
    gameOver = true;
  }
}

int BouncyBall::getExtraLivesNumber(){
  return extraLivesNumber;
}

bool BouncyBall::isGameGoing(){
  return gameGoing;
}

void BouncyBall::countDownFrame(){
  if(racketStartedMoving){
    framesToStartCounter--;
  }
  if(framesToStartCounter <= 0){
    startGame();
  }
}

void BouncyBall::moveWithRacket() {
  racketStartedMoving = true;
  if(!isGameGoing()){
    Point racketCenter = racket->getCenter();
    Point center;
    center.x= racketCenter.x  + (racket->getWidth() / 2.0F) / 3.0F;
    center.y = initialBallPosY;
    setCenter(center);
  }
}

int BouncyBall::getScore() {
  return score;
}

bool BouncyBall::isBallLost(Point center){
  if(center.y >= racket->getCenter().y + racket->getHeight()){
    return true;
  }
  return false;
}

int BouncyBall::getNumberOfBrokenBricks(){
  int count = 0;
  for (auto &collidable : collidables_){
    shared_ptr<Brick> brick = dynamic_pointer_cast<Brick>(collidable);
    if(brick and brick->isBroken()){
      count++;
    }
  }
  return count;
}

void BouncyBall::update() {
  if(isGameGoing()){
    Point center = getCenter();
    for (auto &collidable : collidables_){
      if(collidable->isCollidingWithCircle(center, r_)){
        collideWithEdge(collidable, center);
      }
    }

    score = getNumberOfBrokenBricks();

    if(score == rows*columns){
      gameWon = true;
      stopGame();
      return;
    }

    if (isBallLost(center)){
      stopGame();


    } else{
      center.x = center.x + horizontalSpeed;
      center.y = center.y + verticalSpeed;
      setCenter(center);
    }


  } else{
    countDownFrame();
  }
}
