#include <cmath>
#include <iostream>
#include <stdexcept>
#include <sys/resource.h>

namespace armstrong
{

static int GetXXXValue(const int i, const int j, const int k)
{
    static constexpr int kHundred{100};
    static constexpr int kDecade{10};

    return i * kHundred + j * kDecade + k;
}

static int GetCubed(int i)
{
    return i * i * i;
}

void GetXXXArmstrongNumbers()
{
    std::cout << "Armstrong Numbers from 100 to 999" << std::endl;

    for(int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                const double kNumber = GetXXXValue(i, j, k);
                const double kCubed = GetCubed(i) + GetCubed(j) + GetCubed(k);

                if (kNumber == kCubed)
                {
                    std::cout << kNumber << " is Armstrong Number" << std::endl;
                }
            }
        }
    }
}

}