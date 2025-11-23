#include "IPv4.hpp"
#include <iostream>
#include <sstream>

int main()
{
    IPv4 ip(192,168,0,1);
    std::cout << "Initial IP: " << ip << "\n";

    ++ip;
    std::cout << "After prefix ++: " << ip << "\n";

    ip++;
    std::cout << "After postfix ++: " << ip << "\n";

    --ip;
    std::cout << "After prefix --: " << ip << "\n";

    ip--;
    std::cout << "After postfix --: " << ip << "\n";

    std::stringstream ss("10.0.0.1");
    IPv4 ip2;
    ss >> ip2;
    std::cout << "IP from stringstream: " << ip2 << "\n";

    std::cout << std::boolalpha;
    std::cout << "ip == ip2? " << (ip == ip2) << "\n";
    std::cout << "ip < ip2? " << (ip < ip2) << "\n";

    return 0;
}
