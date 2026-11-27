#include "timer.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

void resetTimer(TimePoint& timer) {
    timer = Clock::now();
}

void printTimer(TimePoint timer) {
    auto now = Clock::now();
    chrono::duration<double> time = now - timer;

    cout << fixed << setprecision(6)
              << time.count() << " segundos\n";
}