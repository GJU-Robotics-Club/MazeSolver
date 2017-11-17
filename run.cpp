#include <stdio.h>
#include <thread>
#include <chrono>
#include "run.h"
#include "Maze.h"
#include "Testing.h"

void __loop() {
    while(!Testing::__stp) {
        loop();
    }
}


int main(int argc, char *argv[]) {
    setup();
    std::thread lpThread(__loop);

    printf("Loop is running to quit press 'q' then Enter\n");
    char in;
    while(!Testing::__stp) {
        scanf("%c", &in);
        if(in == 'q' || in == 'Q') {
            Testing::__stp = 1;
            printf("stopping loop\n");
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    lpThread.join();

    printf("good bye!\n");
    return 0;
}
