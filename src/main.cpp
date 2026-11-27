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
    size_t vector_size = 100000;
    vector<int> random_v = randomVector(vector_size);
    vector<int> sorted_v = sortedVector(vector_size);
    vector<int> inversed_v = inversedSortedVector(vector_size);
    vector<int> vector;

    // Insertion Sort
    vector = random_v;
    cout << "Insertion Sort com vetor desordenado: ";
    resetTimer(timer);
    insertionSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Insertion Sort com vetor ordenado: ";
    resetTimer(timer);
    insertionSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Insertion Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    insertionSort(vector);
    printTimer(timer);

    // Shell Sort
    vector = random_v;
    cout << "\nShell Sort com vetor desordenado: ";
    resetTimer(timer);
    shellSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Shell Sort com vetor ordenado: ";
    resetTimer(timer);
    shellSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Shell Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    shellSort(vector);
    printTimer(timer);

    // Bubble Sort
    vector = random_v;
    cout << "\nBubble Sort com vetor desordenado: ";
    resetTimer(timer);
    bubbleSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Bubble Sort com vetor ordenado: ";
    resetTimer(timer);
    bubbleSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Bubble Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    bubbleSort(vector);
    printTimer(timer);

    // Quick Sort
    vector = random_v;
    cout << "\nQuick Sort com vetor desordenado: ";
    resetTimer(timer);
    quickSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Quick Sort com vetor ordenado: ";
    resetTimer(timer);
    quickSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Quick Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    quickSort(vector);
    printTimer(timer);

    // Selection Sort
    vector = random_v;
    cout << "\nSelection Sort com vetor desordenado: ";
    resetTimer(timer);
    selectionSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Selection Sort com vetor ordenado: ";
    resetTimer(timer);
    selectionSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Selection Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    selectionSort(vector);
    printTimer(timer);

    // Heap Sort
    vector = random_v;
    cout << "\nHeap Sort com vetor desordenado: ";
    resetTimer(timer);
    heapSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Heap Sort com vetor ordenado: ";
    resetTimer(timer);
    heapSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Heap Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    heapSort(vector);
    printTimer(timer);

    // Merge Sort
    vector = random_v;
    cout << "\nMerge Sort com vetor desordenado: ";
    resetTimer(timer);
    mergeSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Merge Sort com vetor ordenado: ";
    resetTimer(timer);
    mergeSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Merge Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    mergeSort(vector);
    printTimer(timer);
    
    // Radix Sort
    /*vector = random_v;
    cout << "\nRadix Sort com vetor desordenado: ";
    resetTimer(timer);
    radixSort(vector);
    printTimer(timer);

    vector = sorted_v;
    cout << "Radix Sort com vetor ordenado: ";
    resetTimer(timer);
    radixSort(vector);
    printTimer(timer);

    vector = inversed_v;
    cout << "Radix Sort com vetor ordenado decrescente: ";
    resetTimer(timer);
    radixSort(vector);
    printTimer(timer);*/

    return 0;
}