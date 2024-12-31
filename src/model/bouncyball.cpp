//
// Created by farrukh on 31/12/24.
//

#include "bouncyball.hpp"



BouncyBall::BouncyBall(Point center, float r, ALLEGRO_COLOR frameColor,
                       ALLEGRO_COLOR fillColor, shared_ptr<Racket> racket) noexcept :
        Circle{center, r, frameColor, fillColor},
        racket_{racket}
{}

void BouncyBall::draw() {
  Point center = getCenter();

  /*
  if (center.x + r_ > windowWidth or center.x - r_ < 0){
    horizontalSpeed = -horizontalSpeed;
  }
  if (center.y + r_> windowHeight or center.y - r_ < 0){
    verticalSpeed = -verticalSpeed;
  }
   */

  if (Circle::contains(Point{0, center.y})or Circle::contains(Point{windowWidth, center.y})){
    horizontalSpeed = -horizontalSpeed;
  }
  if (Circle::contains(Point{center.x, 0})){
    verticalSpeed = -verticalSpeed;
  }

  if (Circle::contains(Point{center.x, windowHeight})){
    //todo change to fully submerge the ball under the screen
    center.y = mid_y;
  }

  if(racket_->contains(Point{center.x, center_.y + r_})){
    float angle = racket_->getAngle(Point{center.x, center_.y + r_});
    horizontalSpeed = cos(angle) * speed;
    verticalSpeed = -sin(angle) * speed;
  }



  center.x = center.x + horizontalSpeed;
  center.y = center.y + verticalSpeed;

  setCenter(center);
  Circle::draw();
}