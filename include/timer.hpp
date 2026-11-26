#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;

void reset_timer(TimePoint& tempo_atual);
void print_timer(TimePoint tempo_atual);

#endif