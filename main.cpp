#include <iostream>

#include <serial_container.hpp>

int main()
{
    serial_container<int> cont;

    cont.push_back(5);
    cont.push_back(6);
    cont.push_back(7);
    cont.push_back(8);
    cont.push_back(9);
    cont.push_back(10);

    cont.show();

    // cont.erase(3);
    // cont.erase(1);

    cont.insert(1, 15);
    cont.insert(7, 98);
    cont.insert(3, 14);

    cont.show();

    std ::cout << "add_elements " << cont[5] << std ::endl;

    std ::cout << cont.size() << std ::endl;

    return 0;
}