#pragma once
#include <iostream>
#include <string>


class Entity_v1
{
public:
    virtual ~Entity_v1() = default;
    virtual void test() = 0;
};

class Entity_v2
{
public:
    virtual ~Entity_v2() = default;
    virtual void test() = 0;
};


class Adapter_v1 : public Entity_v1
{
public:
    virtual void test_v1() = 0; 
    void test() override { test_v1(); }
};

class Adapter_v2 : public Entity_v2
{
public:
    virtual void test_v2() = 0; 
    void test() override { test_v2(); }
};
