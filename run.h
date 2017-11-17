#ifndef RUN_H_INCLUDED
#define RUN_H_INCLUDED

#include "VirtualArduino.h"
#include "Maze.h"
#include "Robot.h"
#include "Testing.h"

Robot bot;

void setup() {
    Testing::initMaze("maze1.txt");
    // bot object, starting x, starting y, orientation, target x, target y
    // coordinates represents the position on the maze grid
    Testing::initRobot(bot, 1, 8, 90, 5, 1);

    Serial.begin(9600);
    Serial.println(bot.readGyroscope());
    Serial.println(bot.readUltrasonicFront());
    bot.moveForwards();
    Serial.println(bot.readUltrasonicFront());
    bot.turnRight();
    Serial.println(bot.readUltrasonicFront());
}

void loop() {
    delay(1000);
}


#endif // RUN_H_INCLUDED
