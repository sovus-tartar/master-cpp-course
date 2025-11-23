#pragma once
#include "Shape.hpp"
#include <numbers>

class Circle final : public Shape
{
public:
    explicit Circle(double radius);

    double perimeter() const override final;
    double area() const override final;

private:
    double radius_;
};
