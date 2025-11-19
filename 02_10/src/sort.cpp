#include <vector>

int median_of_three(std::vector<int> &vector, std::size_t left, std::size_t right)
{
    std::size_t mid = left + (right - left) / 2;

    if (vector[left] > vector[mid])
    {
        std::swap(vector[left], vector[mid]);
    }
    if (vector[left] > vector[right - 1])
    {
        std::swap(vector[left], vector[right - 1]);
    }
    if (vector[mid] > vector[right - 1])
    {
        std::swap(vector[mid], vector[right - 1]);
    }

    return vector[mid];
}

std::size_t hoare_partition(std::vector<int> &vector, std::size_t left, std::size_t right)
{

    int pivot = median_of_three(vector, left, right);

    std::size_t i = left - 1;
    std::size_t j = right;

    while (true)
    {

        do
        {
            ++i;
        } while (vector[i] < pivot);

        do
        {
            --j;
        } while (vector[j] > pivot && j > left);

        if (i >= j)
        {
            break;
        }

        std::swap(vector[i], vector[j]);
    }

    return j + 1;
}

void insertion_sort(std::vector<int> &vector, std::size_t left, std::size_t right)
{
    for (auto i = left + 1; i < right; ++i)
    {
        int key = vector[i];
        auto j = i;

        while (j > left && vector[j - 1] > key)
        {
            vector[j] = vector[j - 1];
            --j;
        }
        vector[j] = key;
    }
}

void hybrid_quick_sort(std::vector<int> &vector, std::size_t left, std::size_t right)
{
    // Малые массивы сортируем вставками
    if (right - left <= 16)
    {
        insertion_sort(vector, left, right);
        return;
    }

    std::size_t partition_index = hoare_partition(vector, left, right);

    hybrid_quick_sort(vector, left, partition_index);
    hybrid_quick_sort(vector, partition_index, right);
}

void sort(std::vector<int> &vector)
{
    if (vector.size() <= 1)
        return;
    hybrid_quick_sort(vector, 0, vector.size());
}
