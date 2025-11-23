#include <iostream>
#include <vector>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Square.hpp"

int main()
{
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Triangle(3.0, 4.0, 5.0));
    shapes.push_back(new Square(4.0));

    for (const auto* s : shapes)
    {
        std::cout << "Perimeter: " << s->perimeter()
                  << ", Area: " << s->area() << "\n";
    }

    
    for (auto* s : shapes)
        delete s;

    return 0;
}
