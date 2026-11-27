#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <vector>

std::vector<int> randomVector(std::size_t size = 1000000);
std::vector<int> sortedVector(std::size_t size = 1000000);
std::vector<int> inversedSortedVector(std::size_t size = 1000000);
std::vector<int> copyVector(const std::vector<int>& original);

#endif