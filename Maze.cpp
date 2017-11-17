#include "Maze.h"
#include <cstdio>
#include <iostream>
void Maze::loadFromFile(std::string fn) {
    FILE* fh = fopen(fn.c_str(), "r");
    int n;
    fscanf(fh, "%d", &n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fscanf(fh, "%d", &maze[j][i]);
        }
    }

    fclose(fh);

    printf("Maze matrix, as read from %s\n", fn.c_str());
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}
