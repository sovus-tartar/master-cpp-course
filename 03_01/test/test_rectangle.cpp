#include <gtest/gtest.h>
#include "rectangle.h"

TEST(rectangle, intersection_basic)
{
    Rectangle a(0, 0, 10, 10);
    Rectangle b(5, 5, 15, 15);
    Rectangle c = intersect_two(a, b);

    EXPECT_EQ(c.x1, 5);
    EXPECT_EQ(c.y1, 5);
    EXPECT_EQ(c.x2, 10);
    EXPECT_EQ(c.y2, 10);
}

TEST(rectangle, intersection_empty)
{
    Rectangle a(0, 0, 5, 5);
    Rectangle b(5, 5, 10, 10);
    Rectangle c = intersect_two(a, b);

    EXPECT_EQ(c.area(), 0);
}

TEST(rectangle, intersect_many)
{
    std::vector<Rectangle> rects;
    rects.push_back(Rectangle(0, 0, 10, 10));
    rects.push_back(Rectangle(2, 2, 8, 8));
    rects.push_back(Rectangle(3, 1, 6, 7));

    Rectangle r = intersect_many(rects);

    EXPECT_EQ(r.x1, 3);
    EXPECT_EQ(r.y1, 2);
    EXPECT_EQ(r.x2, 6);
    EXPECT_EQ(r.y2, 7);
}

TEST(rectangle, bounding)
{
    std::vector<Rectangle> rects;
    rects.push_back(Rectangle(0, 0, 3, 3));
    rects.push_back(Rectangle(10, 10, 12, 12));

    Rectangle b = bounding_rectangle(rects);

    EXPECT_EQ(b.x1, 0);
    EXPECT_EQ(b.y1, 0);
    EXPECT_EQ(b.x2, 12);
    EXPECT_EQ(b.y2, 12);
}
