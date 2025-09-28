#include <classifier.h>
#include <iostream>

namespace classifier
{

void Classify(const char c)
{
    switch(c)
    {
        case 'A' ... 'Z':
            std::cout << "Uppercase letter" << std::endl;
            break;

        case 'a' ... 'z':
            std::cout << "Lowercase Letter" << std::endl;
            break;

        case '0' ... '9':
            std::cout << "Number" << std::endl;
            break;

        case ' ' ... '/': [[fallthrough]];
        case ':' ... '@': [[fallthrough]];
        case '[' ... '`': [[fallthrough]];
        case '{' ... '~': 
            std::cout << "Punctuation mark" << std::endl;
            break;

        default:
            std::cout << "Other symbol" << std::endl;
    }
}

}