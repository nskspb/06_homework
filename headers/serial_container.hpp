#pragma once

#include <IContainers.hpp>

template <typename T>
class serial_container : public IContainers<T>
{
public:
    serial_container() : c_size{}, data{} {}

    void push_back(const T &element) override
    {
        T *data = new T[c_size + 1];
        data[c_size] = element;
    }

    void show()
    {

        for (int i = 0; i < c_size; i++)
        {
            std::cout << data[i] << " ";
        }

        std::cout << std::endl;
    }

    int size() const override
    {
        return c_size;
    }

private:
    int c_size;
    T *data;
};