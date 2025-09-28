#include <collatz.h>
#include <exception>
#include <iostream>
#include <ostream>

int main()
{
    try 
    {
        int maxLen = 0;
        for (int i = 1; i < 100; ++i) {
            int tempLen{};
            if ((tempLen = collatz::GetLength(i)) > maxLen)
                maxLen = tempLen;
            std::cout << "Collatz length i = " << i << " len = " << tempLen << std::endl;
        }
        std::cout << "Maximum Collatz length len = " << maxLen << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}