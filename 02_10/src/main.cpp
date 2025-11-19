#include <algorithm>
#include <sort.h>
#include <iostream>
#include <cassert>

int main()
{

    int nSize{};
    std::cin >> nSize;
    assert(nSize > 0);

    std::vector<int> vector(nSize, 0);

    for (auto i = 0; i < nSize; ++i)
    {
        std::cin >> vector[i];
    }

    std::cout << "Sorting array:" << std::endl << "[";
    for (auto& item : vector)
    {
        std::cout << item << ", ";
    }
    std::cout << "\b\b]" << std::endl;

    sort(vector);
    assert(std::is_sorted(vector.begin(), vector.end()));

    std::cout << "Sorted array:" << std::endl << "[";
    for (auto& item : vector)
    {
        std::cout << item << ", ";
    }
    std::cout << "\b\b]" << std::endl;

    return 0;
}
