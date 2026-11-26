#include "timer.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

void reset_timer(TimePoint& tempo_atual) {
    tempo_atual = Clock::now();
}

void print_timer(TimePoint tempo_atual) {
    auto agora = Clock::now();
    chrono::duration<double> duracao = agora - tempo_atual;

    cout << fixed << setprecision(6)
              << duracao.count() << " segundos\n";
}