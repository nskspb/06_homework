#pragma once

#include "IContainers.hpp"

template <typename T>
class Node1
{
public:
    Node1 *next;
    //  Node *prev;
    T data;

    Node1(T data = T(), Node1 *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class doubly_list_container : public IContainers<T>
{
public:
    doubly_list_container() : head{nullptr}, c_size{} {}

    ~doubly_list_container()
    {
        clear();
    }

    void push_back(const T &element) override
    {
        if (head == nullptr)
        {
            head = new Node1<T>(element);
        }
        else
        {
            Node1<T> *tmp = head;

            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node1<T>(element);
        }

        c_size++;
    }

    void push_front(const T &element)
    {
        head = new Node1<T>(element, head);
        c_size++;
    }

    void pop_front()
    {
        Node1<T> *tmp = head;
        head = head->next;
        delete tmp;
        c_size--;
    }

    void insert(int position, const T &element)
    {
        if (position == 0)
        {
            push_front(element);
        }
        else
        {
            Node1<T> *previous = head;

            for (int i = 0; i < position - 1; ++i)
            {
                previous = previous->next;
            }

            Node1<T> *follow = new Node1<T>(element, previous->next);
            previous->next = follow;
        }
        c_size++;
    }

    void erase(int position)
    {
        if (position == 0)
        {
            pop_front();
        }
        else
        {
            Node1<T> *previous = head;

            for (int i = 0; i < position - 1; ++i)
            {
                previous = previous->next;
            }

            Node1<T> *follow = previous->next;
            previous->next = follow->next;
            delete follow;
        }
        c_size--;
    };

    T &operator[](int position) const
    {
        int count = 0;
        Node1<T> *tmp = head;
        while (tmp->next != nullptr)
        {
            if (count == position)
            {
                return tmp->data;
            }
            tmp = tmp->next;
            count++;
        }

        return tmp->data;
    };

    void show() override
    {
        Node1<T> *tmp = head;
        for (int i = 0; i < c_size; ++i)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    };

    int size() const override
    {
        return c_size;
    }

    void clear()
    {
        while (c_size)
        {
            Node1<T> *tmp = head;

            head = head->next;

            delete tmp;
            c_size--;
        }
    }

private:
    int c_size;
    Node1<T> *head;
    // Node1<T> *tail;
};