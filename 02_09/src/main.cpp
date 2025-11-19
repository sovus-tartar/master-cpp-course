#include <iostream>
#include <numeric>
#include "divisors.h"

int main()
{
    int a, b;
    std::cin >> a >> b;

    int gcd_rec = gcd_recursive(a, b);
    int gcd_iter = gcd_iterative(a, b);
    int gcd_std = std::gcd(a, b);

    int lcm_cust = lcm_custom(a, b);
    int lcm_std = std::lcm(a, b);

    std::cout << "gcd_rec: " << gcd_rec << std::endl;
    std::cout << "gcd_iter: " << gcd_iter << std::endl;
    std::cout << "gcd_std: " << gcd_std << std::endl;

    std::cout << "lcm_cust: " << lcm_cust << std::endl;
    std::cout << "lcm_std: " << lcm_std << std::endl;

    return 0;
}