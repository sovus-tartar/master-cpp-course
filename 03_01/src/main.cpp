#include <iostream>
#include <vector>
#include "rectangle.h"

int main()
{
    std::vector<Rectangle> rects;
    rects.push_back(Rectangle(0, 0, 10, 10));
    rects.push_back(Rectangle(3, 4, 12, 14));
    rects.push_back(Rectangle(2, 2, 8, 9));

    Rectangle inter = intersect_many(rects);
    Rectangle bound = bounding_rectangle(rects);

    std::cout << "Intersection rectangle:\n";
    std::cout << "x1=" << inter.x1 << " y1=" << inter.y1
              << " x2=" << inter.x2 << " y2=" << inter.y2 << "\n";
    std::cout << "Area: " << inter.area() << "\n\n";

    std::cout << "Bounding rectangle:\n";
    std::cout << "x1=" << bound.x1 << " y1=" << bound.y1
              << " x2=" << bound.x2 << " y2=" << bound.y2 << "\n";
    std::cout << "Area: " << bound.area() << "\n";

    return 0;
}
