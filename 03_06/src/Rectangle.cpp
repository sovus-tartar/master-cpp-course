#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height)
{
}

double Rectangle::perimeter() const
{
    return 2.0 * (width_ + height_);
}

double Rectangle::area() const
{
    return width_ * height_;
}
