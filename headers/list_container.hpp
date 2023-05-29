#pragma once

#include "IContainers.hpp"

template <typename T>
class Node
{
public:
    Node *next;
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

    list_container(const list_container &other) : c_size{}, head{nullptr}
    {
        std::cout << "copy" << std::endl;
        for (int i = 0; i < other.c_size; ++i)
        {
            this->push_back(other[i]);
        }
    }

    list_container &operator=(const list_container &other)
    {
        clear();
        std::cout << "operator=" << std::endl;
        for (int i = 0; i < other.c_size; ++i)
        {
            this->push_back(other[i]);
        }
        return *this;
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

    void insert(int position, const T &element) override
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
            c_size++;
        }
    }

    void erase(int position) override
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
            c_size--;
        }
    }

    T &operator[](int position) const override
    {
        Node<T> *tmp = head;

        for (int i = 0; i < position; ++i)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    void show() override
    {
        Node<T> *tmp = head;
        for (int i = 0; i < c_size; ++i)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    int size() const override
    {
        return c_size;
    }

    const char *name() const override
    {
        return "list_container";
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
};