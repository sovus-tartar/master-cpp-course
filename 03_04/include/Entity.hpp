#pragma once
#include <string>

class Entity
{
private:
    
    int test_v1() const;
    std::string test_v2(int x) const;

public:
    
    class Attorney_v1
    {
        friend class Tester_v1;
        static int call(const Entity& e) { return e.test_v1(); }
    };

    class Attorney_v2
    {
        friend class Tester_v2;
        static std::string call(const Entity& e, int x) { return e.test_v2(x); }
    };

    Entity() = default;
};


class Tester_v1
{
public:
    static int test(const Entity& e)
    {
        return Entity::Attorney_v1::call(e);
    }
};

class Tester_v2
{
public:
    static std::string test(const Entity& e, int x)
    {
        return Entity::Attorney_v2::call(e, x);
    }
};
