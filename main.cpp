#include <iostream>

#include "headers/serial_container.hpp"
#include "headers/list_container.hpp"
#include "headers/doubly_list_container.hpp"

namespace tests
{
    void example()
    {
        serial_container<int> a;
        a.push_back(42);
        a.push_back(43);
        a.push_back(44);
        auto b = a;
        b.show();
    }
}

int main()
{
    const size_t container_count = 3;

    IContainers<int> *container[container_count];

    container[0] = new serial_container<int>{};
    container[1] = new list_container<int>{};
    container[2] = new doubly_list_container<int>{};

    for (size_t i = 0; i < container_count; ++i)
    {

        auto &c = *container[i];
        std::cout << "-------------------" << c.name() << "------------------------------" << std::endl;
        for (int j = 0; j < 10; ++j)
        {
            c.push_back(j);
        }
        c.show();

        std::cout << "size = " << c.size() << std::endl;

        c.erase(6);
        c.erase(4);
        c.erase(2);
        c.show();

        c.insert(0, 10);
        c.show();

        c.insert(c.size() / 2, 20);
        c.show();

        c.push_back(30);
        c.show();

        std::cout << std::endl;

        delete container[i];
    }

    tests::example();
    return 0;
}