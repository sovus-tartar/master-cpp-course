#include <gtest/gtest.h>
#include "List.hpp"

TEST(ListTest, EmptyInitially)
{
    List lst;
    EXPECT_TRUE(lst.empty());
}

TEST(ListTest, PushFrontAndBack)
{
    List lst;
    lst.push_front(1);
    EXPECT_FALSE(lst.empty());
    lst.push_back(2);
    lst.push_front(0);
    int middle = lst.get();
    EXPECT_EQ(middle, 1);
}

TEST(ListTest, PopFrontAndBack)
{
    List lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.pop_front();
    EXPECT_EQ(lst.get(), 3);
    lst.pop_back();
    EXPECT_EQ(lst.get(), 2);
}

TEST(ListTest, SingleElement)
{
    List lst;
    lst.push_back(42);
    EXPECT_EQ(lst.get(), 42);
    lst.pop_front();
    EXPECT_TRUE(lst.empty());
}

TEST(ListTest, GetMiddleEven)
{
    List lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4); // [1,2,3,4] → middle should be 3
    EXPECT_EQ(lst.get(), 3);
}

TEST(ListTest, GetMiddleOdd)
{
    List lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3); // [1,2,3] → middle should be 2
    EXPECT_EQ(lst.get(), 2);
}
