//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_CANVAS_HPP
#define ARKANOID_CANVAS_HPP

#include <memory>
#include "racket.hpp"
#include "bouncyball.hpp"

/*--------------------------------------------------
Canvas class.

One instance of the canvas class is made by the
MainWindow class.

The fltk system via MainWindow calls:

draw 60 times a second
mouseClick whenever the mouse is clicked
keyPressed whenever a key is pressed

Any drawing code should be called ONLY in draw
or methods called by draw. If you try to draw
elsewhere it will probably crash.
--------------------------------------------------*/

class Canvas {

    Racket racket_ = Racket(Point{mid_x,mid_y+180}, 250.0F, 15.0F, COLOR_BLACK, COLOR_BLUE);
    BouncyBall bouncyBall_ = BouncyBall(Point{mid_x,mid_y}, 10.0F, COLOR_BLACK, COLOR_RED, &racket_);
public:
    Canvas() = default;
    void draw();
    void mouseClick(Point mouseLoc);
    void mouseMove(Point mouseMove){}
    bool keyPressed(int keyCode);  // return True if the event was handled
};

#endif //ARKANOID_CANVAS_HPP
