#include <stdexcept>

int mathematical_mod(int dividend, int divisor)
{
    if (divisor == 0)
    {
        throw std::invalid_argument("Divisor cannot be zero");
    }

    int remainder = dividend % divisor;

    if (remainder < 0)
    {
        remainder += std::abs(divisor);
    }

    return remainder;
}

int gcd_recursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd_recursive(b, mathematical_mod(a, b));
}

int gcd_iterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = mathematical_mod(a, b);
        a = temp;
    }
    return a;
}

int lcm_custom(int a, int b)
{
    int gcd_value = gcd_iterative(a, b);
    return std::abs ((a / gcd_value) * b);
}