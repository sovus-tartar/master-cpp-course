#pragma once

#include <vector>

struct Rectangle
{
    int x1;
    int y1;
    int x2;
    int y2;

    Rectangle();
    Rectangle(int left, int top, int right, int bottom);

    int width() const;
    int height() const;
    int area() const;
};

Rectangle intersect_two(const Rectangle& a, const Rectangle& b);
Rectangle intersect_many(const std::vector<Rectangle>& rects);
Rectangle bounding_rectangle(const std::vector<Rectangle>& rects);
