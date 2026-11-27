#include "vector.hpp"

#include <numeric>
#include <random>

std::vector<int> randomVector(std::size_t size) {
    std::vector<int> arr(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000000);

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = dist(gen);
    }

    return arr;
}

std::vector<int> sortedVector(std::size_t size) {
    std::vector<int> arr(size);
    std::iota(arr.begin(), arr.end(), 0);
    return arr;
}

std::vector<int> inversedSortedVector(std::size_t size) {
    std::vector<int> arr(size);
    std::iota(arr.rbegin(), arr.rend(), 0);
    return arr;
}

std::vector<int> copyVector(const std::vector<int>& original) {
    std::vector<int> copied = original;
    return copied;             
}