#pragma once

class Square {
public:
    explicit Square(double side);

    double perimeter() const;
    double area() const;

private:
    double side_;
};
