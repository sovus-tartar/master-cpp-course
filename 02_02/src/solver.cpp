#include <cmath>
#include <iostream>

#include <solver.h>
#include <stdexcept>

namespace SquareEquation
{

bool IsEqual(double a, double b) { return std::abs(a - b) < kEpsilon;}

void Solves::Print() const 
{
    std::cout << "Solutions: " << nSolves << std::endl;
    switch (nSolves)
    {
        case 0:
            break;
        case 1:
            std::cout << "x = " << xArr[0] << std::endl;
            break;
        case 2:
            std::cout << "x1 = " << xArr[0] << "\t" << "x2 = " << xArr[1] << std::endl;
            break;
        default:
            std::cerr << "Unknown number of solutions: " << nSolves << std::endl; 
    }
}

Equation::Equation(const double _a, const double _b, const double _c) : a(_a), b(_b), c(_c) 
{
    if (IsEqual(a, 0))
    {
        throw std::invalid_argument("'a' can't be 0");
    }
}

Solves Equation::Solve() const
{
    double discriminant{NAN};
    discriminant = b * b - 4 * a * c;

    if (IsEqual(discriminant, 0))
    {
        const double x = (-b) / (2 * a);
        return Solves{x};
    }

    if (discriminant < 0)
    {
        return Solves{};
    }

    // discriminant > 0
    const double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
    const double x2 = (-b - std::sqrt(discriminant)) / (2 * a);

    return Solves{x1, x2};
}

}