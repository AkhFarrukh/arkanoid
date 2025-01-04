//
// Created by farrukh on 31/12/24.
//

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

One instance of the canvas class is made by the
MainWindow class.

The fltk system via MainWindow calls:

draw 60 times a second
mouseClick whenever the mouse is clicked
keyPressed whenever a key is pressed

Any drawing code should be called ONLY in draw
or methods called by draw. If you try to update
elsewhere it will probably crash.
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

    [[nodiscard]] const vector<shared_ptr<Drawable>>& getVectorOfDrawables() const;

    int getExtraLivesNumber();
    int getScore();
    bool isGameOver();
    bool isGameWon();
};

#endif //ARKANOID_CANVAS_HPP
