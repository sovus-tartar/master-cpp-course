#include "Rational.hpp"
#include <iostream>
#include <sstream>

int main()
{
    Rational x(1), y(2,1);

    std::cout << "x = " << x << ", y = " << y << "\n";

    x += y;
    std::cout << "x += y -> x = " << x << "\n";

    x -= y;
    std::cout << "x -= y -> x = " << x << "\n";

    x *= y;
    std::cout << "x *= y -> x = " << x << "\n";

    x /= y;
    std::cout << "x /= y -> x = " << x << "\n";

    std::cout << std::boolalpha;
    std::cout << "x == y? " << (x == y) << "\n";
    std::cout << "x < y? " << ((x <=> y) < 0) << "\n";

    std::stringstream ss("3/4");
    Rational z;
    ss >> z;
    std::cout << "z from stringstream: " << z << "\n";

    return 0;
}
