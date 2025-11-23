#include <gtest/gtest.h>
#include "IPv4.hpp"
#include <sstream>

TEST(IPv4Test, IncrementDecrement)
{
    IPv4 ip(192,168,0,255);
    ++ip;
    EXPECT_EQ(ip[3], 0);
    EXPECT_EQ(ip[2], 1);

    ip++;
    EXPECT_EQ(ip[3], 1);

    --ip;
    EXPECT_EQ(ip[3], 0);

    ip--;
    EXPECT_EQ(ip[3], 255);
}

TEST(IPv4Test, Comparison)
{
    IPv4 ip1(10,0,0,1);
    IPv4 ip2(10,0,0,2);

    EXPECT_TRUE(ip1 < ip2);
    EXPECT_TRUE(ip1 <= ip2);
    EXPECT_FALSE(ip1 > ip2);
    EXPECT_FALSE(ip1 >= ip2);
    EXPECT_TRUE(ip1 != ip2);
    EXPECT_FALSE(ip1 == ip2);
}

TEST(IPv4Test, IO)
{
    std::stringstream ss("192.168.1.1");
    IPv4 ip;
    ss >> ip;
    EXPECT_EQ(ip[0], 192);
    EXPECT_EQ(ip[1], 168);
    EXPECT_EQ(ip[2], 1);
    EXPECT_EQ(ip[3], 1);

    std::stringstream out;
    out << ip;
    EXPECT_EQ(out.str(), "192.168.1.1");
}
    