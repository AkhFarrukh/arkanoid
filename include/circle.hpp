//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_CIRCLE_HPP
#define ARKANOID_CIRCLE_HPP



#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"


class Circle : public virtual Drawable {
protected:
    Point         center_;
    float         r_;
    ALLEGRO_COLOR frameColor_, fillColor_;

public:
    Circle(Point center, float r, ALLEGRO_COLOR frameColor = COLOR_BLACK,
           ALLEGRO_COLOR fillColor = COLOR_WHITE) noexcept;
    void                draw() override;
    void                setFillColor(ALLEGRO_COLOR newFillColor);
    void                setFrameColor(ALLEGRO_COLOR newFrameColor);
    [[nodiscard]] bool  contains(Point point) const override;
    [[nodiscard]] Point getCenter() const;
    void                setCenter(Point newCenter);

};

#endif //ARKANOID_CIRCLE_HPP
