#include "Robot.h"
#include <stdio.h>
#include "Maze.h"

void Robot::moveForwards() {
    int ori = m_orientation +0.3;
    switch(ori) {
    case 0:
        m_pos.x += 1;
        break;
    case 90:
        m_pos.y -= 1;
        break;
    case 180:
        m_pos.x -= 1;
        break;
    case 270:
        m_pos.y += 1;
        break;
    default:
        printf("broken orientation\n");
    }

    if(Testing::maze.maze[m_pos.x][m_pos.y] == 1) {
        printf("crashed into wall\n");
        Testing::__stp = 1;
    }
}

void Robot::moveBackwards(){
    int ori = m_orientation + 0.3;

    switch(ori) {
    case 0:
        m_pos.x -= 1;
        break;
    case 90:
        m_pos.y += 1;
        break;
    case 180:
        m_pos.x += 1;
        break;
    case 270:
        m_pos.y -= 1;
        break;
    default:
        printf("broken orientation\n");
    }
    if(Testing::maze.maze[m_pos.x][m_pos.y] == 1) {
        printf("crashed into wall\n");
        Testing::__stp = 1;
    }
}

void Robot::turnRight(){
    int ori = m_orientation + 0.3;
    ori -= 90;
    m_orientation = abs(ori % 360);
}

void Robot::turnLeft(){
    int ori = m_orientation +0.3;
    ori += 90;
    m_orientation = abs(ori % 360);
}

float Robot::readUltrasonicLeft(){
    int ori = m_orientation +0.3;
    float dist = 0;
    switch(ori) {
    case 0:
        for(int i = m_pos.y-1; i > 0; --i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }

        break;

    case 90:
        for(int i = m_pos.x-1; i > 0; --i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;

    case 180:
        for(int i = m_pos.y+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;

    case 270:
       for(int i = m_pos.x+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    default:
        printf("broken orientation\n");
    }

    return dist;
}

float Robot::readUltrasonicRight(){
    int ori = m_orientation +0.3;
    float dist = 0;
    switch(ori) {
    case 0:
        for(int i = m_pos.y+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    case 90:
        for(int i = m_pos.x+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }

        break;
    case 180:
        for(int i = m_pos.y-1; i > 0; --i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    case 270:
        for(int i = m_pos.x-1; i > 0; --i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    default:
        printf("broken orientation\n");
    }

    return dist;
}

float Robot::readUltrasonicFront(){
    int ori = m_orientation +0.3;

    float dist = 0;
    switch(ori) {
    case 0:
        for(int i = m_pos.x+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }

        break;
    case 90:
        for(int i = m_pos.y-1; i > 0; --i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    case 180:
        for(int i = m_pos.x-1; i > 0; --i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    case 270:
        for(int i = m_pos.y+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    default:
        printf("broken orientation\n");
    }

    return dist;
}

float Robot::readUltrasonicBack(){
    int ori = m_orientation +0.3;

    float dist = 0;
    switch(ori) {
    case 0:
        for(int i = m_pos.x-1; i > 0; --i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }

        break;
    case 90:
        for(int i = m_pos.y+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    case 180:
        for(int i = m_pos.x+1; i < MAX_MAZE_SIZE; ++i) {
            if(Testing::maze.maze[i][m_pos.y] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    case 270:
        for(int i = m_pos.y-1; i > 0; --i) {
            if(Testing::maze.maze[m_pos.x][i] != 1) {
                dist += 15;
            } else {
                break;
            }
        }
        break;
    default:
        printf("broken orientation\n");
    }

    return dist;
}

float Robot::readGyroscope(){
    return m_orientation;
}

bool Robot::isOnTarget() {
    return m_pos == Testing::target;
}
