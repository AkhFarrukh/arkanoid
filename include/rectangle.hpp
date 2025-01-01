//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_RECTANGLE_HPP
#define ARKANOID_RECTANGLE_HPP


#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "modelcolor.hpp"

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

struct RectangleInfo{
    Point center;
    float         w, h;
    ModelColor frameColor, fillColor;
};

class Rectangle : public virtual Drawable {
protected:
    Point center_;
    float         w_, h_;
    ModelColor frameColor_, fillColor_;

public:

    Rectangle(Point center, float w, float h,
              ModelColor frameColor = FRAME_COLOR,
              ModelColor fillColor  = DEFAULT_COLOR) noexcept;

    void                draw() override;
    void                setFillColor(ModelColor newFillColor);
    void                setFrameColor(ModelColor newFrameColor);
    [[nodiscard]] bool  contains(Point point) const override;
    [[nodiscard]] Point getCenter() const;

    [[nodiscard]] RectangleInfo getRectangleInfo() const;
};
#endif //ARKANOID_RECTANGLE_HPP
