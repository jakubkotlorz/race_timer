#include <iostream>

#include "racetimer.h"

int main() {
    TimerConfig config;
    RaceTimer race_timer{config};
    race_timer.run();

    int n = 5;
    while(n-- > 0) {
        std::string command;
        std::cin >> command;
        race_timer.run_cmd(command);
    }
    return 0;
}
