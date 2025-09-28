#include <exponent.h>
#include <exception>
#include <iomanip>
#include <iostream>
#include <ostream>

int main()
{
    try
    {
        double eps{};
        std::cin >> eps;
        if (std::cin.fail())
        {
            throw std::runtime_error("Can't read a number from stdin");
        }
        
        int precision = static_cast<int>(std::ceil(-std::log10(eps)));
        if (precision < 0)
        {
            precision = 0;
        }
        std::cout << std::fixed << std::setprecision(precision);

        auto exp = exponent::GetE(eps);
        std::cout << "e = " << exp << "+-" << eps << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}