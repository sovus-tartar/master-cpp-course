#include "Client.hpp"

int main()
{
    Client c;

    
    c.test_v1(); 
    c.test_v2(); 

    
    Entity_v1* e1 = &c;
    Entity_v2* e2 = &c;

    e1->test(); 
    e2->test(); 

    return 0;
}
