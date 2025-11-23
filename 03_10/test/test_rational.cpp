#include <gtest/gtest.h>
#include "Rational.hpp"
#include <sstream>

TEST(RationalTest, Arithmetic)
{
    Rational x(1), y(2,1);

    x += y;
    EXPECT_EQ(x, Rational(3,1));
    x -= y;
    EXPECT_EQ(x, Rational(1,1));
    x *= y;
    EXPECT_EQ(x, Rational(2,1));
    x /= y;
    EXPECT_EQ(x, Rational(1,1));
}

TEST(RationalTest, IncrementDecrement)
{
    Rational x(1);
    ++x;
    EXPECT_EQ(x, Rational(2,1));
    x++;
    EXPECT_EQ(x, Rational(3,1));
    --x;
    EXPECT_EQ(x, Rational(2,1));
    x--;
    EXPECT_EQ(x, Rational(1,1));
}

TEST(RationalTest, Comparison)
{
    Rational a(1,2), b(2,3);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(a > b);
    EXPECT_FALSE(a >= b);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);

    Rational c(3,4), d(3,4);
    EXPECT_TRUE(c == d);
    EXPECT_FALSE(c != d);
    EXPECT_FALSE(c < d);
    EXPECT_FALSE(c > d);
    EXPECT_TRUE(c <= d);
    EXPECT_TRUE(c >= d);
}

TEST(RationalTest, IO)
{
    std::stringstream ss("5/6");
    Rational r;
    ss >> r;
    EXPECT_EQ(r, Rational(5,6));

    std::stringstream out;
    out << r;
    EXPECT_EQ(out.str(), "5/6");
}
