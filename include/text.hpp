//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_TEXT_HPP
#define ARKANOID_TEXT_HPP


#include <string>

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"

#include "view.hpp" //todo del

using namespace std;
/*--------------------------------------------------
Text class.

Use to display text on the screen. For example:

Text("Hello!", {250, 250}).draw();

will create a text temporary instance with the
string "Hello!" centered at 250, 250 and will
call update on the temporary.

It should have all the features you need and you
should not need to edit it.
--------------------------------------------------*/

class Text: public virtual Drawable {
    string        s_;
    Point         center_;
    ALLEGRO_COLOR color_;

public:
    // Constructor
    Text(string text, Point center, ALLEGRO_COLOR color = COLOR_BLACK)
            : s_{text}, center_{center}, color_{color} {}

    // Draw
    void update() override;

    // Setters and getters
    string getString() { return s_; }
    void   setString(const string &newString) { s_ = newString; }
    Point  getCenter() { return center_; }
    void   setCenter(Point newCenter) { center_ = newCenter; }
    bool   contains(Point p) const override;
};

#endif //ARKANOID_TEXT_HPP
