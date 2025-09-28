#include <binet.h>
#include <cmath>
#include <iostream>

namespace binet
{

int GetFibonacciVal(const int n)
{
    const double kPhi = (1 + std::sqrt(5)) / 2;
    const double kXi = (1 - std::sqrt(5)) / 2;
    const double kF_n = (std::pow(kPhi, n) - std::pow(kXi, n)) / std::sqrt(5);
    return static_cast<int>(kF_n);
}

}