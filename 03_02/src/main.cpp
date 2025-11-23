#include <iostream>
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Square.hpp"

int main()
{
    Circle c(2.0);
    Triangle t(3.0, 4.0, 5.0);
    Square s(4.0);

    std::cout << "Circle perimeter: " << c.perimeter() << "\n";
    std::cout << "Circle area:      " << c.area() << "\n\n";

    std::cout << "Triangle perimeter: " << t.perimeter() << "\n";
    std::cout << "Triangle area:      " << t.area() << "\n\n";

    std::cout << "Square perimeter: " << s.perimeter() << "\n";
    std::cout << "Square area:      " << s.area() << "\n";

    return 0;
}
