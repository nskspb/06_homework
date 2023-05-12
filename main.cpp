#include <iostream>

#include "headers/serial_container.hpp"
#include "headers/list_container.hpp"
#include "headers/doubly_list_container.hpp"

int main()
{
    const size_t container_count = 3;

    IContainers<int> *container[container_count];

    container[0] = new serial_container<int>{};
    container[1] = new list_container<int>{};
    container[2] = new doubly_list_container<int>{};

    for (size_t i = 0; i < container_count; ++i)
    {
        std::cout << "-------------------" << container[i]->name() << "------------------------------" << std::endl;
        for (int j = 0; j < 10; ++j)
        {
            container[i]->push_back(j);
        }
        container[i]->show();

        std::cout << "size = " << container[i]->size() << std::endl;

        container[i]->erase(6);
        container[i]->erase(4);
        container[i]->erase(2);
        container[i]->show();

        container[i]->insert(0, 10);
        container[i]->show();

        container[i]->insert(container[i]->size() / 2, 20);
        container[i]->show();

        container[i]->push_back(30);
        container[i]->show();

        std::cout << std::endl;

        delete container[i];
    }
    return 0;
}