//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_CLICKABLE_HPP
#define ARKANOID_CLICKABLE_HPP
#include "drawable.hpp"

/*--------------------------------------------------
Clickable class.
--------------------------------------------------*/
class Clickable : public virtual Drawable {
protected:
    Clickable()                             = default;
    Clickable(const Clickable &)            = default;
    Clickable(Clickable &&)                 = default;
    Clickable &operator=(const Clickable &) = default;
    Clickable &operator=(Clickable &&)      = default;

public:
    virtual void onClick() {};
    ~Clickable() override  = default;
};

#endif //ARKANOID_CLICKABLE_HPP
