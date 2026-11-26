#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <string>

struct AlgoritmoOrdenacao {
    std::string nome;
    void (*funcao)(std::vector<int>&);
};

void insertionSort(std::vector<int>& arr);

void shellSort(std::vector<int>& arr);

void bubbleSort(std::vector<int>& arr);

void quickSort(std::vector<int>& arr);

void selectionSort(std::vector<int>& arr);

void heapSort(std::vector<int>& arr);

void mergeSort(std::vector<int>& arr);

void radixSort(std::vector<int>& arr);

std::vector<AlgoritmoOrdenacao> obter_algoritmos();

#endif