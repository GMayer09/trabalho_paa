#include "sorts.hpp"
#include <algorithm>
#include <cstdint>
#include <utility>

using namespace std;

void insertionSort(vector<int>& arr) {
    const size_t n = arr.size();

    if (n < 2) {
        return;
    }

    for (size_t i = 1; i < n; ++i) {
        int key = arr[i];
        size_t j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

void shellSort(std::vector<int>& arr) {
    const size_t n = arr.size();
    size_t gap = 1;

    if (n < 2) {
        return;
    }
    
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    while (gap >= 1) {
        for (size_t i = gap; i < n; ++i) {
            int key = arr[i];
            size_t j = i;

            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
        gap /= 3;
    }
}

void bubbleSort(std::vector<int>& arr) {
    const size_t n = arr.size();

    if (n < 2) {
        return;
    }

    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;

        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

static int partition(std::vector<int>& arr, int left, int right) { // Função auxiliar para o quickSort
    int mid = left + (right - left) / 2;
    swap(arr[mid], arr[right]);
    
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

static void quickSortHelper(std::vector<int>& arr, int low, int high) { // Função auxiliar para o quickSort
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(std::vector<int>& arr) {
    if (arr.size() < 2) {
        return;
    }
    quickSortHelper(arr, 0, arr.size() - 1);
}

void selectionSort(std::vector<int>& arr) {
    const size_t n = arr.size();

    if (n < 2) {
        return;
    }
    
    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;

        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void heapSort(std::vector<int>& arr) {
    // TODO: implementar Heapsort
}

void intercala(std::vector<int>& arr, int inicio, int meio, int fim) {

}

void mergeSortAux(std::vector<int>& arr, int inicio, int fim) {

}

void mergeSort(std::vector<int>& arr) {
    mergeSortAux(arr, 0, arr.size() - 1);
}

void radixSort(std::vector<int>& arr) {
    // TODO: implementar Radix Sort
}

std::vector<AlgoritmoOrdenacao> obter_algoritmos() {
    return {
        {"Insertion Sort", insertionSort},
        {"Shellsort",      shellSort},
        {"Bubblesort",     bubbleSort},
        {"Quicksort",      quickSort},
        {"Selection Sort", selectionSort},
        {"Heapsort",       heapSort},
        {"Mergesort",      mergeSort},
        {"Radix Sort",     radixSort},
    };
}
