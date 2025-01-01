//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_BOUNCYBALL_HPP
#define ARKANOID_BOUNCYBALL_HPP

#include <cmath>
#include <memory>

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "racket.hpp"
#include "circle.hpp"

/*--------------------------------------------------------------
 *
 --------------------------------------------------------------*/
class BouncyBall : public virtual Circle{
    /*
     * https://www.youtube.com/watch?v=lpvH6MStSis&list=PLgLT8uqXESN84XNkhn7MT-HIi-BYzFWqZ&index=44
     */
private:
    const float speed = 3.0F ;
    float horizontalSpeed = 0.0F * speed;
    float verticalSpeed = 1.0F * speed;

    shared_ptr<Racket> racket_; //needed a destructor or shared

public:
    BouncyBall(Point center, float r, ModelColor frameColor,
               ModelColor fillColor, shared_ptr<Racket> racket) noexcept;

    void makeMove();

    void draw() override;
};

#endif //ARKANOID_BOUNCYBALL_HPP
