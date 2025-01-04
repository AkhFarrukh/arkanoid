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


  Bouncing from walls and bricks code is taken from this video:
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

    void inverseXSpeed();
    void inverseYSpeed();
    int getNumberOfBrokenBricks(); //recount broken bricks to update score

    //this method is called to get the edge on which the collision occurred and change direction of the ball based on type of collidable
    void collideWithEdge(shared_ptr<CollidableRectangle> collidable, Point center);
    //gets a rebound angle ang changes horizontal and vertical speeds accordingly
    void changeSpeedBasedOnRacketAngle(shared_ptr<Racket> racket, Point center);
    void defaultCollide(CollisionType edge);//collision handler with a wall or a brick
    void racketCollide(CollisionType edge, shared_ptr<Racket> racket, Point center);//collision handler with racket. it can only collide with the top of the racket.
    void countDownFrame();//counts down one frame from framesToStartCounter when waiting at the beginning
    shared_ptr<Racket> findRacket();//finds a pointer to racket in a vector of pointers to all drawables
    void startGame(); //start the current round
    void stopGame();// stop the round
    bool isGameGoing();

public:
    BouncyBall(Point center, float r, ModelColor frameColor, ModelColor fillColor,
               vector<shared_ptr<CollidableRectangle>>& collidables) noexcept;
    void update(); //make changes for ball position for current frame
    void moveWithRacket(); //move ball with racket before the game starts
    bool isBallLost(Point center); //is ball passed the point of no return under the racket?
    int getExtraLivesNumber();
    bool isGameOver(); //were all lives spent?
    bool isGameWon();//were all bricks destroyed?
    int getScore();
};

#endif //ARKANOID_BOUNCYBALL_HPP
