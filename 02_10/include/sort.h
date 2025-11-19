#pragma once
#include <vector>

int median_of_three(std::vector<int> &vector, std::size_t left, std::size_t right);
std::size_t hoare_partition(std::vector<int> &vector, std::size_t left, std::size_t right);
void insertion_sort(std::vector<int> &vector, std::size_t left, std::size_t right);
void hybrid_quick_sort(std::vector<int> &vector, std::size_t left, std::size_t right);
void sort(std::vector<int> &vector);