#include <iostream>

#include "headers/serial_container.hpp"
#include "headers/list_container.hpp"
#include "headers/doubly_list_container.hpp"

int main()
{
    /*  std::cout << "----------------------serial_container-------------------------" << std::endl;

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

      list.insert(0, 2);
      list.insert(3, 8);
      list.push_front(1);
      list.show();

      list.pop_front();
      list.erase(2);
      list.show();

      std::cout << "list[2] = " << list[2] << std::endl;
      std::cout << "size = " << list.size() << std::endl;

      doubly_list_container<int> doubly_list;

      doubly_list.push_back(4);
      doubly_list.push_back(8);
      doubly_list.push_back(12);
      doubly_list.push_back(16);

      doubly_list.show();*/

    /* const size_t container_count = 3;

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
     }*/

    std::cout << std::endl
              << "----------proverka------------" << std::endl;
    doubly_list_container<int> doub;

    doub.push_front(2);
    doub.push_back(5);
    doub.insert(0, 13);
    doub.insert(3, 11);
    doub.insert(1, 10);
    doub.insert(3, 14);
    doub.insert(3, 3);
    doub.insert(5, 6);
    doub.insert(7, 8);
    doub.show();
    doub.pop_front();
    doub.pop_back();
    doub.show();
    doub.erase(5);
    doub.show();
    std::cout << "doub[2] = " << doub[2] << std ::endl;
    std::cout << "doub[5] = " << doub[5] << std ::endl;

    std::cout << std::endl;

    return 0;
}