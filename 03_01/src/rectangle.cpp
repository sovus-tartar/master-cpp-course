#include "rectangle.h"
#include <cassert>

Rectangle::Rectangle()
    : x1(0), y1(0), x2(0), y2(0)
{
}

Rectangle::Rectangle(int left, int top, int right, int bottom)
    : x1(left), y1(top), x2(right), y2(bottom)
{
}

int Rectangle::width() const
{
    return (x2 > x1) ? (x2 - x1) : 0;
}

int Rectangle::height() const
{
    return (y2 > y1) ? (y2 - y1) : 0;
}

int Rectangle::area() const
{
    return width() * height();
}

Rectangle intersect_two(const Rectangle& a, const Rectangle& b)
{
    int left   = (a.x1 > b.x1) ? a.x1 : b.x1;
    int top    = (a.y1 > b.y1) ? a.y1 : b.y1;
    int right  = (a.x2 < b.x2) ? a.x2 : b.x2;
    int bottom = (a.y2 < b.y2) ? a.y2 : b.y2;

    if (right <= left || bottom <= top)
    {
        return Rectangle(0, 0, 0, 0);
    }

    return Rectangle(left, top, right, bottom);
}

Rectangle intersect_many(const std::vector<Rectangle>& rects)
{
    if (rects.empty())
    {
        return Rectangle(0, 0, 0, 0);
    }

    Rectangle result = rects[0];

    for (std::size_t i = 1; i < rects.size(); ++i)
    {
        result = intersect_two(result, rects[i]);
        if (result.area() == 0)
        {
            return Rectangle(0, 0, 0, 0);
        }
    }

    return result;
}

Rectangle bounding_rectangle(const std::vector<Rectangle>& rects)
{
    assert(!rects.empty());

    int left   = rects[0].x1;
    int top    = rects[0].y1;
    int right  = rects[0].x2;
    int bottom = rects[0].y2;

    for (std::size_t i = 1; i < rects.size(); ++i)
    {
        if (rects[i].x1 < left)   left   = rects[i].x1;
        if (rects[i].y1 < top)    top    = rects[i].y1;
        if (rects[i].x2 > right)  right  = rects[i].x2;
        if (rects[i].y2 > bottom) bottom = rects[i].y2;
    }

    return Rectangle(left, top, right, bottom);
}
