#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "timer.hpp"
#include "sorts.hpp"
#include "vector.hpp"

using namespace std;

int main() {
    TimePoint timer;
    size_t vector_size = 10000000z;
    vector<int> random_v = randomVector(vector_size);
    vector<int> sorted_v = sortedVector(vector_size);
    vector<int> inversed_v = inversedSortedVector(vector_size);
    vector<int> vector;

    vector = random_v;
    cout << "QuickSort com vetor desordenado: ";
    resetTimer(timer);
    quickSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "QuickSort com vetor ordenado: ";
    resetTimer(timer);
    quickSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "QuickSort com vetor ordenado decrescente: ";
    resetTimer(timer);
    quickSort(vector);
    printTimer(timer);
    
    return 0;
}