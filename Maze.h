#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <string>
#define MAX_MAZE_SIZE 100
class Maze {
public:
    void loadFromFile(std::string fn);
    char maze [MAX_MAZE_SIZE][MAX_MAZE_SIZE];

private:


};

#endif // MAZE_H_INCLUDED
