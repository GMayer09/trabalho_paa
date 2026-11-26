#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "timer.hpp"
#include "sorts.hpp"

using namespace std;

int main() {
    vector<int> v(1'000'000);
    mt19937 rng(42);
    for (int& x : v) x = rng();

    vector<int> v1 = v;
    vector<int> v2 = v;
    vector<int> v3 = v;
    vector<int> v4 = v;
    vector<int> v5 = v;
    vector<int> v6 = v;
    vector<int> v7 = v;
    vector<int> v8 = v;

    TimePoint timer;

    cout << "QuickSort: ";
    reset_timer(timer);
    quickSort(v1);
    print_timer(timer);
    
    return 0;
}