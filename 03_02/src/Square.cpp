#include "Square.hpp"

Square::Square(double side)
    : side_(side)
{
}

double Square::perimeter() const
{
    return 4.0 * side_;
}

double Square::area() const
{
    return side_ * side_;
}
