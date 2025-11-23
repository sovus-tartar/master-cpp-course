#pragma once
#include "Polygon.hpp"

class Triangle : public Polygon
{
public:
    Triangle(double a, double b, double c);

    double perimeter() const override;
    double area() const override;

private:
    double a_, b_, c_;
};
