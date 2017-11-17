#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED
#include "Point.h"
//#include "Robot.h"
#include <string>
#include "Maze.h"
class Robot;
namespace Testing {
    extern void initRobot(Robot &bot, int x, int y, float orientation, int targetX, int targetY);
    extern void initMaze(const std::string &fn);
    extern Point target;
    extern Maze maze;
    extern char __stp;
}


#endif // TESTING_H_INCLUDED
