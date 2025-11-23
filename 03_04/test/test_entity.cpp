#include <gtest/gtest.h>
#include "Entity.hpp"

TEST(EntityTests, TestV1)
{
    Entity e;
    int res = Tester_v1::test(e);
    EXPECT_EQ(res, 42);
}

TEST(EntityTests, TestV2)
{
    Entity e;
    std::string res = Tester_v2::test(e, 7);
    EXPECT_EQ(res, "Value_7");
}
