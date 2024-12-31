//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_OBSERVER_HPP
#define ARKANOID_OBSERVER_HPP
/*--------------------------------------------------
Observer
--------------------------------------------------*/
struct Observer {
    virtual void subjectChanged() = 0;
    virtual ~Observer()           = default;

protected:
    Observer()                            = default;
    Observer(const Observer &)            = default;
    Observer(Observer &&)                 = default;
    Observer &operator=(const Observer &) = default;
    Observer &operator=(Observer &&)      = default;
};
#endif //ARKANOID_OBSERVER_HPP
