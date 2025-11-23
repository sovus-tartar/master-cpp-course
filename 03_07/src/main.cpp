#include "Vector.hpp"
#include <print>

int main()
{
    Vector v;

    std::print("Empty? {}\n", v.empty());

    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
        std::print("i = {}, size = {}, capacity = {}\n", i, v.size(), v.capacity());
    }

    std::print("After push_back: size = {}, capacity = {}\n", v.size(), v.capacity());

    v.clear();
    std::print("After clear: size = {}, capacity = {}\n", v.size(), v.capacity());
}
