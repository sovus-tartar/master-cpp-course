#pragma once

#include <numbers>

class Circle {
public:
    explicit Circle(double r);

    double perimeter() const;
    double area() const;

private:
    double radius_;
};

