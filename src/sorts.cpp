#include "sorts.hpp"
#include <algorithm>
#include <cstdint>
#include <utility>

using namespace std;

// Insertion Sort
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

// Shell Sort
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

// Bubble Sort
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

// Quick Sort
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

// Selection Sort
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

// Heap Sort
static void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge Sort
void interleaveMerge(std::vector<int>& arr, int bg, int md, int end) {
    int i = bg;
    int j = md + 1;
    int k = 0;
    int size = end - bg + 1;
    std::vector<int> array_temp(size);
    
    while (i <= md && j <= end) {
        if (arr[i] <= arr[j]) {
            array_temp[k++] = arr[i++];
        } else {
            array_temp[k++] = arr[j++];
        }
    }

    while (i <= md) {
        array_temp[k++] = arr[i++];
    }

    while (j <= end) {
        array_temp[k++] = arr[j++];
    }

    for (int idx = 0; idx < k; idx++) {
        arr[bg + idx] = array_temp[idx];
    }
}

void mergeSortAux(std::vector<int>& arr, int bg, int end) {
    if (bg < end) {
        int md = bg + (end - bg) / 2;
        mergeSortAux(arr, bg, md);
        mergeSortAux(arr, md + 1, end);
        interleaveMerge(arr, bg, md, end);
    }
}

void mergeSort(std::vector<int>& arr) {
    mergeSortAux(arr, 0, arr.size() - 1);
}

void countingSortByDigit(vector<int>& arr, int exp) {
    int n = static_cast<int>(arr.size());
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = move(output);
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
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
