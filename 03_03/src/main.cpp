#include "List.hpp"

int main()
{
    List lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_front(0);

    lst.show(); // [0, 1, 2, 3]

    lst.pop_front();
    lst.pop_back();

    lst.show(); // [1, 2]

    int mid = lst.get();
    std::cout << "Middle value: " << mid << "\n"; // 2

    return 0;
}
