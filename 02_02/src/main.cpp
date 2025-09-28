#include <iostream>
#include <solver.h>
#include <stdexcept>

int main()
{
    std::cout << "Square Equation Solver" << std::endl;
    try 
    {
        std::cout << "Format: a * x^2 + b * x + c = 0" << std::endl \
                  << "Enter coefficients a b c" << std::endl;
        double a{NAN}, b{NAN}, c{NAN};
        std::cin >> a >> b >> c;
        if (std::cin.fail())
        {
            throw std::invalid_argument("Can't read arguments from stdin");
        }

        const SquareEquation::Equation equation{a, b, c};
        const auto solves = equation.Solve();
        solves.Print();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
