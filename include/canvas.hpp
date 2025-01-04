

#ifndef ARKANOID_CANVAS_HPP
#define ARKANOID_CANVAS_HPP

#include <memory>
#include <vector>
#include <ranges>

#include "drawable.hpp"
#include "racket.hpp"
#include "bouncyball.hpp"
#include "modelcolor.hpp"
#include "collidablerectangle.hpp"
#include "brick.hpp"
#include "modelInteractions.hpp"



using namespace std;
/*--------------------------------------------------
Canvas class.
--------------------------------------------------*/

class Canvas {
    vector<shared_ptr<Drawable> > drawables {};
    vector<shared_ptr<CollidableRectangle> > collidables {};
    shared_ptr<Racket> racket;
    shared_ptr<BouncyBall> ball;

public:
    Canvas();
    void update();
    bool keyPressed(ModelInteractions keyCode);  // return True if the event was handled

    //returns a vector of pointers to drawables for ball to use.
    [[nodiscard]] const vector<shared_ptr<Drawable>>& getVectorOfDrawables() const;
    int getExtraLivesNumber();
    int getScore();
    bool isGameOver();
    bool isGameWon();
};

#endif //ARKANOID_CANVAS_HPP
