#include "Circle.hpp"

Circle::Circle(double r)
    : radius_(r)
{
}

double Circle::perimeter() const
{
    return 2.0 * std::numbers::pi * radius_;
}

double Circle::area() const
{
    return std::numbers::pi * radius_ * radius_;
}
