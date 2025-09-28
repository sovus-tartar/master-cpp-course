#include "classifier.h"
#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        char c{0};
        std::cin >> c;
        if (std::cin.fail())
        {
            throw std::invalid_argument("Failed to read symbol from stdin");
        }
        classifier::Classify(c);
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}