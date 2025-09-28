#include <cmath>
#include <iostream>
#include <stdexcept>
#include <sys/resource.h>

namespace exponent
{

// e = 1 + 1 + 1/2 + 1/(2*3) + 1/(2*3*4) + ...
double GetE(const double epsilon)
{
    int i = 1;
    double eSum{0};
    double temp{1};

    while (temp > epsilon)
    {
        eSum += temp;
        temp /= i;
        ++i;
    }
    return eSum;
}

}