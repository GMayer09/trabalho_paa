#include <algorithm>
#include <iostream>
#include <vector>
#include "sorts.hpp"

int main() {
    std::vector<int> v = {5, 2, 9, 1, 5, 6, -3};

    quickSort(v);

    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}