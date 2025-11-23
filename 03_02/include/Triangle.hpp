#pragma once

class Triangle {
public:
    Triangle(double a, double b, double c);

    double perimeter() const;
    double area() const;

private:
    double a_;
    double b_;
    double c_;
};

