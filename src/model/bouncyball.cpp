//
// Created by farrukh on 31/12/24.
//

#include "bouncyball.hpp"

#include <utility>



BouncyBall::BouncyBall(Point center, float r, ModelColor frameColor,
                       ModelColor fillColor,
                       vector<shared_ptr<CollidableRectangle>>& collidables) noexcept :
        Circle{center, r, frameColor, fillColor},
        collidables_{collidables}
{}


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

void BouncyBall::update() {
  Point center = getCenter();

 //TODO use clamp before changing velocity
  for (auto &collidable : collidables_){
    if(collidable->isCollidingWithCircle(center, r_)){
      collideWithEdge(collidable, center);
    }
  }

  if (Circle::contains(Point{center.x, windowHeight- 5})){
    //todo change to fully submerge the ball under the screen
    center.y = mid_y;
  }

  center.x = center.x + horizontalSpeed;
  center.y = center.y + verticalSpeed;

  setCenter(center);
}