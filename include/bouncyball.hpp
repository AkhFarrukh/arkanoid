//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_BOUNCYBALL_HPP
#define ARKANOID_BOUNCYBALL_HPP

#include <cmath>
#include <memory>
#include <vector>

#include "drawable.hpp"
#include "point.hpp"
#include "constants.hpp"
#include "racket.hpp"
#include "circle.hpp"
#include "collidablerectangle.hpp"
#include "brick.hpp"

using namespace std;

/*--------------------------------------------------------------


 https://www.youtube.com/watch?v=lpvH6MStSis&list=PLgLT8uqXESN84XNkhn7MT-HIi-BYzFWqZ&index=44
 --------------------------------------------------------------*/
class BouncyBall : public virtual Circle{
private:
    const float speed = gameSpeed;
    float horizontalSpeed = 0.0F *speed;
    float verticalSpeed = 0.0F *speed;
    bool gameGoing = false;
    bool racketStartedMoving = false;
    int extraLivesNumber = 2;
    float framesToStartCounter = timeBeforeGameStart * refreshPerSecond;

    bool gameOver;
    int score = 0;
    bool gameWon;
    const float initialBallPosY;
    vector<shared_ptr<CollidableRectangle>> collidables_;
    shared_ptr<Racket> racket;


public:
    BouncyBall(Point center, float r, ModelColor frameColor, ModelColor fillColor,
               vector<shared_ptr<CollidableRectangle>>& collidables) noexcept;

    void update() ;


    void inverseXSpeed();
    void inverseYSpeed();
    int getNumberOfBrokenBricks();
    void collideWithEdge(shared_ptr<CollidableRectangle> collidable, Point center);
    void changeSpeedBasedOnRacketAngle(shared_ptr<Racket> racket, Point center);
    void defaultCollide(CollisionType edge);
    void racketCollide(CollisionType edge, shared_ptr<Racket> racket, Point center);




    void startGame();

    void stopGame();

    bool isGameGoing();

    void countDownFrame();

    shared_ptr<Racket> findRacket();

    void moveWithRacket();

    bool isBallLost(Point center);

    int getExtraLivesNumber();

    bool isGameOver();

    bool isGameWon();



    int getScore();
};

#endif //ARKANOID_BOUNCYBALL_HPP
