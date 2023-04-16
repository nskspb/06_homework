#pragma once

#include "IContainers.hpp"

template <typename T>
class Node
{
public:
    Node *next;
    //  Node *prev;
    T data;

    Node(T data = T(), Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class list_container : public IContainers<T>
{
public:
    list_container() : head{nullptr}, c_size{} {}

    ~list_container()
    {
        clear();
    }

    void push_back(const T &element) override
    {
        if (head == nullptr)
        {
            head = new Node<T>(element);
        }
        else
        {
            Node<T> *tmp = head;

            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node<T>(element);
        }

        c_size++;
    }

    void push_front(const T &element)
    {
        head = new Node<T>(element, head);
        c_size++;
    }

    void pop_front()
    {
        Node<T> *tmp = head;
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
            Node<T> *previous = head;

            for (int i = 0; i < position - 1; ++i)
            {
                previous = previous->next;
            }

            Node<T> *follow = new Node<T>(element, previous->next);
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
            Node<T> *previous = head;

            for (int i = 0; i < position - 1; ++i)
            {
                previous = previous->next;
            }

            Node<T> *follow = previous->next;
            previous->next = follow->next;
            delete follow;
        }
        c_size--;
    };

    T &operator[](int position) const
    {
        int count = 0;
        Node<T> *tmp = head;
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
        Node<T> *tmp = head;
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
            Node<T> *tmp = head;

            head = head->next;

            delete tmp;
            c_size--;
        }
    }

private:
    int c_size;
    Node<T> *head;
    // Node<T> *tail;
};