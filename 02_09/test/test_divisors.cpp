#include <gtest/gtest.h>
#include <divisors.h>
#include <numeric>


void test_algorithms(int a, int b) {
    int gcd_rec = gcd_recursive(a, b);
    int gcd_iter = gcd_iterative(a, b);
    int gcd_std = std::gcd(a, b);

    int lcm_cust = lcm_custom(a, b);
    int lcm_std = std::lcm(a, b);

    EXPECT_EQ(gcd_rec, gcd_std);
    EXPECT_EQ(gcd_iter, gcd_std);
    EXPECT_EQ(lcm_cust, lcm_std);
}

TEST(divisor, test1)
{
    test_algorithms(12, 18);
}

TEST(divisor, test2)
{
    test_algorithms(17, 13);
}

TEST(divisor, test3)
{
    test_algorithms(48, 180);
}

TEST(divisor, test4)
{
    test_algorithms(100, 25);
}

TEST(divisor, test5)
{
    test_algorithms(0, 5);
}

TEST(divisor, test6)
{
    test_algorithms(7, 7);
}

TEST(divisor, test_negative)
{
    test_algorithms(-12, 18);
}