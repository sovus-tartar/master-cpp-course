#include <gtest/gtest.h>
#include "Client.hpp"

TEST(ClientTest, TestV1)
{
    Client c;

    testing::internal::CaptureStdout();
    c.test_v1();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Client::test_v1 implementation\n");
}

TEST(ClientTest, TestV2)
{
    Client c;

    testing::internal::CaptureStdout();
    c.test_v2();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Client::test_v2 implementation\n");
}

TEST(ClientTest, TestThroughBasePointers)
{
    Client c;

    Entity_v1* e1 = &c;
    Entity_v2* e2 = &c;

    testing::internal::CaptureStdout();
    e1->test();
    std::string out1 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    e2->test();
    std::string out2 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(out1, "Client::test_v1 implementation\n");
    EXPECT_EQ(out2, "Client::test_v2 implementation\n");
}
