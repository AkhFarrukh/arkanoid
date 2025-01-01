//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_INTRECTANGLE_HPP
#define ARKANOID_INTRECTANGLE_HPP



#include "textrectangle.hpp"
#include "subject.hpp"
/*--------------------------------------------------
IntRectangle
--------------------------------------------------*/
class IntRectangle : public TextRectangle, public Subject {
    int  theInteger = 0;

protected:
    IntRectangle(const IntRectangle &)            = default;
    IntRectangle(IntRectangle &&)                 = default;
    IntRectangle &operator=(const IntRectangle &) = default;
    IntRectangle &operator=(IntRectangle &&)      = default;

public:
    IntRectangle(Point center, float w, float h, int theInteger)
            : TextRectangle{center, w, h, ""}, theInteger{theInteger} {
    }
    operator int() const { return theInteger; }
    int  getInteger() const { return theInteger; }
    void setInteger(int newInteger) {
      theInteger = newInteger;
    }
    ~IntRectangle() override = default;
};

#endif //ARKANOID_INTRECTANGLE_HPP
