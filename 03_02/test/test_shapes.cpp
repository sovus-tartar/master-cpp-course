#include <gtest/gtest.h>
#include <cmath>
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Square.hpp"

TEST(CircleTests, Perimeter)
{
    Circle c(1.0);
    double expected = 2.0 * std::numbers::pi;
    EXPECT_NEAR(c.perimeter(), expected, 1e-9);
}

TEST(CircleTests, Area)
{
    Circle c(1.0);
    double expected = std::numbers::pi;
    EXPECT_NEAR(c.area(), expected, 1e-9);
}

TEST(TriangleTests, Perimeter)
{
    Triangle t(3.0, 4.0, 5.0);
    EXPECT_DOUBLE_EQ(t.perimeter(), 12.0);
}

TEST(TriangleTests, Area)
{
    Triangle t(3.0, 4.0, 5.0);
    EXPECT_NEAR(t.area(), 6.0, 1e-9);
}

TEST(SquareTests, Perimeter)
{
    Square s(2.0);
    EXPECT_DOUBLE_EQ(s.perimeter(), 8.0);
}

TEST(SquareTests, Area)
{
    Square s(2.0);
    EXPECT_DOUBLE_EQ(s.area(), 4.0);
}
