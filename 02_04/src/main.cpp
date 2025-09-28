#include <armstrong.h>
#include <exception>
#include <iostream>
#include <ostream>

int main()
{
    try
    {
        armstrong::GetXXXArmstrongNumbers();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}