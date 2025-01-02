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

void BouncyBall::update() {
  Point center = getCenter();

  /*
  if (center.x + r_ > windowWidth or center.x - r_ < 0){
    horizontalSpeed = -horizontalSpeed;
  }
  if (center.y + r_> windowHeight or center.y - r_ < 0){
    verticalSpeed = -verticalSpeed;
  }
   */
 //TODO use clamp before changing velocity
  for (auto &collidable : collidables_){
    if(collidable->isCollidingWithCircle(center, r_)){
      CollisionType edge = collidable->getCollidingEdgeType(center, r_);
      switch (edge) {
        case TOP_EDGE_COLLISION:{
          shared_ptr<Racket> racket = dynamic_pointer_cast<Racket>(collidable);
          if(racket){
            float angle = racket->getAngle(Point{center.x, center_.y + r_});
            horizontalSpeed = cos(angle) * speed;
            verticalSpeed = -sin(angle) * speed;
          } else{
            verticalSpeed = -verticalSpeed;
          }
          break;
        }
        case BOTTOM_EDGE_COLLISION:
          verticalSpeed = -verticalSpeed;
          break;
        case LEFT_EDGE_COLLISION:
          horizontalSpeed = -horizontalSpeed;
          break;
        case RIGHT_EDGE_COLLISION:
          horizontalSpeed = -horizontalSpeed;
          break;
        case NO_COLLISION:
          break;
      }
    }
  }

  if (Circle::contains(Point{center.x, windowHeight- 5})){
    //todo change to fully submerge the ball under the screen
    center.y = mid_y;
  }
  /*
  if (Circle::contains(Point{0, center.y})or Circle::contains(Point{windowWidth, center.y})){
    horizontalSpeed = -horizontalSpeed;
  }
  if (Circle::contains(Point{center.x, 0})){
    verticalSpeed = -verticalSpeed;
  }



  if(racket_->contains(Point{center.x, center_.y + r_})){
    float angle = racket_->getAngle(Point{center.x, center_.y + r_});
    horizontalSpeed = cos(angle) * speed;
    verticalSpeed = -sin(angle) * speed;
  }

  */

  center.x = center.x + horizontalSpeed;
  center.y = center.y + verticalSpeed;

  setCenter(center);
}