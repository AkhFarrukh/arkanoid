//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_SUBJECT_HPP
#define ARKANOID_SUBJECT_HPP

#include <vector>
#include "observer.hpp"

using namespace std;
/*--------------------------------------------------
Subject
--------------------------------------------------*/
class Subject {
    vector<Observer *> observers;  // Should be weak_ptr s

protected:
    Subject()                           = default;
    Subject(const Subject &)            = default;
    Subject(Subject &&)                 = default;
    Subject &operator=(const Subject &) = default;
    Subject &operator=(Subject &&)      = default;

public:
    void registerObserver(Observer *observer) { observers.push_back(observer); }
    void removeObserver(Observer *observer) { erase(observers, observer); }
    void notifyObservers() const {
      for (const auto &observer : observers) {
        observer->subjectChanged();
      }
    }
    virtual ~Subject() = default;
};

#endif //ARKANOID_SUBJECT_HPP
