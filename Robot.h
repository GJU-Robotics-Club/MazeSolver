#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "Point.h"
#include "Testing.h"
class Robot {
public:
    void moveForwards();
    void moveBackwards();
    void turnRight();
    void turnLeft();
    float readUltrasonicLeft();
    float readUltrasonicRight();
    float readUltrasonicFront();
    float readUltrasonicBack();
    float readGyroscope();
    bool isOnTarget();

private:
    Point m_pos;
    float m_orientation;
    friend void Testing::initRobot(Robot& bot, int x, int y, float orientation, int targetX, int targetY);
};

#endif // ROBOT_H_INCLUDED
