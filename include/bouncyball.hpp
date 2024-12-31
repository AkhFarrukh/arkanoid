//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_BOUNCYBALL_HPP
#define ARKANOID_BOUNCYBALL_HPP

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
    float horizontalSpeed = 4.5F;
    float verticalSpeed = 4.0F;

    Racket* racket_ = nullptr; //needed a destructor or shared

public:
    BouncyBall(Point center, float r, ALLEGRO_COLOR frameColor,
               ALLEGRO_COLOR fillColor, Racket * racket) noexcept;

    void draw() override;
};

#endif //ARKANOID_BOUNCYBALL_HPP
