#include <gtest/gtest.h>
#include <sort.h>

TEST(sort, test1)
{
    std::vector<int> vec = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    sort(vec);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));

}
TEST(sort, test2)
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(vec);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(sort, test3)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    sort(vec);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));

}

TEST(sort, test4)
{
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    sort(vec);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(sort, test5)
{
    auto size = 10000uz;
    std::vector<int> vec(size, 0);

    for (auto i = 0uz; i < size; ++i)
    {
        vec[i] = size - i;
    }

    sort(vec);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(sort, test6)
{
    std::vector<int> vec = {1};
    sort(vec);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(sort, test7)
{
    std::vector<int> vec;
    sort(vec);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));

}