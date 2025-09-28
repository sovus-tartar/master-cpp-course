#include <analyser.h>
#include <exception>
#include <iostream>

int main()
{
    try 
    {
        analyser::AnalyseInput();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}