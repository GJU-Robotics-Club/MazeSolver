#include "Testing.h"
#include "Robot.h"
namespace Testing {
    void initRobot(Robot &bot, int posX, int posY, float orientation, int targetX, int targetY) {
        bot.m_pos.x = posX;
        bot.m_pos.y = posY;

        bot.m_orientation = orientation;

        target = Point(targetX, targetY);
    }

    void initMaze(const std::string &fn) {
        maze.loadFromFile(fn);
    }

    Point target;
    Maze maze;
    char __stp = 0;
}
