//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_TEXTRECTANGLE_HPP
#define ARKANOID_TEXTRECTANGLE_HPP


#include <string>

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "rectangle.hpp"
#include "text.hpp"

/*--------------------------------------------------
TextRectangle
--------------------------------------------------*/
class TextRectangle : public Text, public Rectangle {
protected:
    TextRectangle(const TextRectangle &)            = default;
    TextRectangle(TextRectangle &&)                 = default;
    TextRectangle &operator=(const TextRectangle &) = default;
    TextRectangle &operator=(TextRectangle &&)      = default;

public:
    TextRectangle(Point center, float w, float h, string text)
            : Text{std::move(text), center}, Rectangle{center, w, h} {}
    void draw() override {
      Rectangle::draw();
      Text::draw();
    }
    bool contains(Point p) const override { return Rectangle::contains(p); }
    ~TextRectangle() override = default;
};



#endif //ARKANOID_TEXTRECTANGLE_HPP
