#include <iostream>

#include "headers/serial_container.hpp"
#include "headers/list_container.hpp"

int main()
{
    std::cout << "----------------------serial_container-------------------------";

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

    std::cout << "----------------------list_container-------------------------" << std::endl;

    list_container<int> list;

    list.push_back(3);
    list.push_back(6);
    list.push_back(9);
    list.push_back(12);

    list.show();

    list.insert(2, 8);
    list.push_front(1);
    list.show();

    list.pop_front();
    list.erase(2);
    list.show();

    std::cout << "list[2] = " << list[2] << std::endl;
    std::cout << "size = " << list.size() << std::endl;

    return 0;
}