#pragma once
#include "Entity.hpp"
#include <string>

class Client : public Adapter_v1, public Adapter_v2
{
public:
    void test_v1() override;
    void test_v2() override;
};
