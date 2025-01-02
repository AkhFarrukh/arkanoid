//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_BOUNCYBALL_HPP
#define ARKANOID_BOUNCYBALL_HPP

#include <cmath>
#include <memory>
#include <vector>

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "racket.hpp"
#include "circle.hpp"
#include "collidablerectangle.hpp"

using namespace std;

/*--------------------------------------------------------------
 *
 --------------------------------------------------------------*/
class BouncyBall : public virtual Circle{
    /*
     * https://www.youtube.com/watch?v=lpvH6MStSis&list=PLgLT8uqXESN84XNkhn7MT-HIi-BYzFWqZ&index=44
     */
private:
    const float speed = 8.0F ;
    float horizontalSpeed = 0.0F * speed;
    float verticalSpeed = 1.0F * speed;

    vector<shared_ptr<CollidableRectangle>>& collidables_;

public:
    BouncyBall(Point center, float r, ModelColor frameColor, ModelColor fillColor,
               vector<shared_ptr<CollidableRectangle>>& collidables) noexcept;

    void makeMove();

    void update() ;
};

#endif //ARKANOID_BOUNCYBALL_HPP
