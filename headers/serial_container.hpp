#pragma once

#include "IContainers.hpp"

template <typename T>
class serial_container : public IContainers<T>
{
public:
    serial_container() : c_size{}, capacity{}, data{nullptr} {}

    ~serial_container()
    {
        delete[] data;
    }

    void swap(const serial_container &first, const serial_container &second)
    {
        std::swap(first.c_size, second.c_size);
        std::swap(first.data, second.data);
    }

    serial_container(const serial_container &other)
    {
        std::cout << "copyyyyyyyyy";
        c_size = other.c_size;
        data = new T[c_size];
        for (int i = 0; i < c_size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    serial_container &operator=(const serial_container &other)
    {
        std::cout << "prisv cop  ";
        serial_container tmp{other};
        swap(*this, tmp);
        return *this;
    }

    serial_container(const serial_container &&other)
    {
        std::cout << "  pereeemesh  ";
        *this = std::move(other);
    }

    serial_container &operator=(const serial_container &&other)
    {
        std::cout << "prisv perem  ";
        swap(*this, other);
        return *this;
    }

    void push_back(const T &element) override
    {
        if (c_size == capacity)
        {
            change_capacity();
            T *tmp = new T[capacity];
            for (int i = 0; i < c_size; ++i)
            {
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
        }
        data[c_size++] = element;
    }

    void insert(int position, const T &element) override
    {
        if (c_size == capacity)
        {
            change_capacity();
            T *tmp = new T[capacity];
            for (int i = 0; i < c_size; ++i)
            {
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
        }
        c_size++;
        for (int i = c_size; i > position; --i)
        {
            data[i] = data[i - 1];
        }
        data[position] = element;
    }

    void erase(int position) override
    {
        for (int i = position; i < c_size; ++i)
        {
            data[i] = data[i + 1];
        }
        c_size--;
    }

    T &operator[](int position) const override
    {
        return data[position];
    }

    void show() override
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

    const char *name() const override
    {
        return "serial_container";
    }

private:
    mutable int c_size;
    int capacity;
    mutable T *data;

    void change_capacity()
    {
        if (capacity == 0)
        {
            capacity++;
            return;
        }
        else
        {
            capacity = (capacity * 3 + 1) / 2;
        }
    }
};
