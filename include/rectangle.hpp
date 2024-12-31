//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_RECTANGLE_HPP
#define ARKANOID_RECTANGLE_HPP


#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"

using namespace std;
/*--------------------------------------------------
Rectangle class.

Use to display a filled-in rectangle on the screen
with different colors for the fill and the border
--------------------------------------------------*/
/*--------------------------------------------------
Rectangle class.

Use to display a filled-in rectangle on the screen
with different colors for the fill and the border

It should have all the features you need and you
should not need to edit it.
--------------------------------------------------*/

class Rectangle : public virtual Drawable {
protected:
    Point center_;
    float         w_, h_;
    ALLEGRO_COLOR frameColor_, fillColor_;

public:
    Rectangle(Point center, float w, float h,
              ALLEGRO_COLOR frameColor = COLOR_BLACK,
              ALLEGRO_COLOR fillColor  = COLOR_WHITE) noexcept;
    void                draw() override;
    void                setFillColor(ALLEGRO_COLOR newFillColor);
    void                setFrameColor(ALLEGRO_COLOR newFrameColor);
    [[nodiscard]] bool  contains(Point point) const override;
    [[nodiscard]] Point getCenter() const;
};
#endif //ARKANOID_RECTANGLE_HPP
