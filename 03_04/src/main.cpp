#include <iostream>
#include "Entity.hpp"

int main()
{
    Entity e;

    int res1 = Tester_v1::test(e);
    std::string res2 = Tester_v2::test(e, 5);

    std::cout << "Tester_v1 result: " << res1 << "\n";
    std::cout << "Tester_v2 result: " << res2 << "\n";

    return 0;
}