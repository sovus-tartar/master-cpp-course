#pragma once
#include "Polygon.hpp"

class Rectangle : public Polygon
{
public:
    Rectangle(double width, double height);

    double perimeter() const override final;
    double area() const override final;

protected:
    double width_, height_;
};
