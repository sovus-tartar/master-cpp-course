#include <gtest/gtest.h>
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Square.hpp"

TEST(ShapeTests, Circle)
{
    Circle c(1.0);
    EXPECT_NEAR(c.perimeter(), 2.0 * std::numbers::pi, 1e-9);
    EXPECT_NEAR(c.area(), std::numbers::pi, 1e-9);
}

TEST(ShapeTests, Triangle)
{
    Triangle t(3.0, 4.0, 5.0);
    EXPECT_DOUBLE_EQ(t.perimeter(), 12.0);
    EXPECT_NEAR(t.area(), 6.0, 1e-9);
}

TEST(ShapeTests, Square)
{
    Square s(2.0);
    EXPECT_DOUBLE_EQ(s.perimeter(), 8.0);
    EXPECT_DOUBLE_EQ(s.area(), 4.0);
}
