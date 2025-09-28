#include <binet.h>
#include <exception>
#include <iostream>
#include <ostream>

int main()
{
    try
    {
        int n{};
        std::cin >> n;
        if (std::cin.fail())
        {
            throw std::invalid_argument("Can't read arguments from stdin");
        }

        const int kFibVal = binet::GetFibonacciVal(n);
        std::cout << "F_" << n << " = " << kFibVal << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}