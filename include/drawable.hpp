//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_DRAWABLE_HPP
#define ARKANOID_DRAWABLE_HPP

#include <memory>
#include "point.hpp"

using namespace std;

struct DrawableInfo{
  virtual ~DrawableInfo() = default;
};

/*--------------------------------------------------
Drawable class.
--------------------------------------------------*/
class Drawable {
protected:
    Drawable()                             = default;
    Drawable(const Drawable &)            = default;
    Drawable(Drawable &&)                 = default;
    Drawable &operator=(const Drawable &) = default;
    Drawable &operator=(Drawable &&)      = default;

public:
    virtual bool contains(Point p) const = 0;
    virtual void update()                 = 0;
    virtual ~Drawable()                 = default;
    virtual  shared_ptr<DrawableInfo> getInfo() =0;
};

#endif //ARKANOID_DRAWABLE_HPP
