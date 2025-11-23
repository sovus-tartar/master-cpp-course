#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle(double a, double b, double c)
    : a_(a), b_(b), c_(c)
{
}

double Triangle::perimeter() const
{
    return a_ + b_ + c_;
}

double Triangle::area() const
{
    const double p = perimeter() / 2.0;
    return std::sqrt(p * (p - a_) * (p - b_) * (p - c_));
}
