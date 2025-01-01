//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_CIRCLE_HPP
#define ARKANOID_CIRCLE_HPP



#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "modelcolor.hpp"

struct CircleInfo{
    Point center;
    float         r;
    ModelColor frameColor, fillColor;
};


class Circle : public virtual Drawable {
protected:
    Point         center_;
    float         r_;
    ModelColor frameColor_, fillColor_;

public:

    Circle(Point center, float r, ModelColor frameColor = FRAME_COLOR,
           ModelColor fillColor = DEFAULT_COLOR) noexcept;
    void                setFillColor(ModelColor newFillColor);
    void                setFrameColor(ModelColor newFrameColor);
    [[nodiscard]] bool  contains(Point point) const override;

    [[nodiscard]] Point getCenter() const;
    void                setCenter(Point newCenter);
    [[nodiscard]] CircleInfo getCircleInfo() const;
};

#endif //ARKANOID_CIRCLE_HPP
