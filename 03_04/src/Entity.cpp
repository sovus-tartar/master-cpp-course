#include "Entity.hpp"
#include <string>


int Entity::test_v1() const
{
    return 42; 
}

std::string Entity::test_v2(int x) const
{
    return "Value_" + std::to_string(x);
}
