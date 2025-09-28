#include <collatz.h>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cmath>

namespace collatz
{

static bool IsEven(const int n)
{
    return (n % 2) == 0;
}

int GetLength(const int n0)
{
    if (n0 <= 0)
    {
        throw std::invalid_argument("n0 <= 0: impossible for Collatz sequence");
    }

    int i = 1;
    int n = n0;

    for (i = 1; ; ++i)
    {
        if (IsEven(n))
        {
            n /= 2;
        }
        else // is Odd
        {
            n = 3 * n + 1;
        }

        if (n == 1)
        {
            break;
        }
    }

    return i;
}

}