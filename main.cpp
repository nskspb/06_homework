#include <iostream>

#include "headers/serial_container.hpp"
#include "headers/list_container.hpp"
#include "headers/doubly_list_container.hpp"

namespace tests
{
    void example()
    {
        list_container<int> a;
        // a.insert(0, 41);
        a.push_back(42);
        // a.erase(0);
        a.show();
        a.push_back(43);
        a.push_back(44);

        list_container<int> b = a;
        b.show();
        b.push_back(12);
        b.push_back(13);
        b.push_back(14);
        b.show();
        a.show();

        list_container<int> c;
        c = std::move(b);
        c.show();
        c.push_back(27);

        list_container<int> d;
        d = c;
        d.push_back(31);
        d.show();

        list_container<int> e = std::move(d);
        e.push_back(32);
        e.show();
    }
}

int main()
{
    tests::example();
    /*const size_t container_count = 3;

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
    }*/

    return 0;
}