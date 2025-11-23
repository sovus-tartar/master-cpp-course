#include <gtest/gtest.h>
#include "Vector.hpp"

TEST(VectorTest, PushBackAndCapacity)
{
    Vector v;
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);

    for (int i = 0; i < 5; ++i)
    {
        v.push_back(i);
        EXPECT_EQ(v[i], i);
    }

    EXPECT_EQ(v.size(), 5);
    EXPECT_GE(v.capacity(), 5);
    EXPECT_FALSE(v.empty());
}

TEST(VectorTest, Clear)
{
    Vector v = {1, 2, 3};
    EXPECT_FALSE(v.empty());
    EXPECT_EQ(v.size(), 3);

    v.clear();
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
}
