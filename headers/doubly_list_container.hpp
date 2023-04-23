#pragma once

#include "IContainers.hpp"

template <typename T>
class Node1
{
public:
    Node1 *next;
    Node1 *prev;
    T data;

    Node1(T data = T(), Node1 *next = nullptr, Node1 *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

template <typename T>
class doubly_list_container : public IContainers<T>
{
public:
    doubly_list_container() : head{nullptr}, tail{nullptr}, c_size{} {}

    ~doubly_list_container()
    {
        clear();
    }

    void push_back(const T &element) override
    {
        if (head == nullptr)
        {
            head = tail = new Node1<T>(element);
            head->next = tail;
            tail->next = nullptr;
            head->prev = nullptr;
        }
        else
        {
            Node1<T> *tmp = new Node1<T>(element);
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        c_size++;
    }

    void push_front(const T &element)
    {
        if (head == nullptr)
        {
            head = tail = new Node1<T>(element);
            head->next = tail;
            tail->next = nullptr;
            head->prev = nullptr;
        }
        else
        {
            Node1<T> *tmp = new Node1<T>(element);
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }
        c_size++;
    }

    void pop_front()
    {
        Node1<T> *tmp = head;
        head = head->next;
        delete tmp;
        c_size--;
    }

    void pop_back()
    {
        Node1<T> *tmp = tail;
        tail = tail->prev;
        delete tmp;
        c_size--;
    }

    void insert(int position, const T &element) override
    {
        if (position == 0)
        {
            push_front(element);
        }
        else if (position == c_size)
        {
            push_back(element);
        }
        else if (c_size / 2 - position >= 0)
        {
            Node1<T> *previous = head;

            for (int i = 0; i < position - 1; ++i)
            {
                previous = previous->next;
            }

            Node1<T> *follow = new Node1<T>(element, previous->next, previous);
            previous->next = follow;
            c_size++;
        }
        else
        {
            Node1<T> *follow = tail;
            for (int i = c_size - 1; i >= position; --i)
            {
                follow = follow->prev;
            }
            follow->next = new Node1<T>(element, follow->next, follow);
            follow->next->next->prev = follow->next;
            c_size++;
        }
    }

    void erase(int position) override
    {
        if (position == 0)
        {
            pop_front();
        }
        else if (position == c_size - 1)
        {
            pop_back();
        }
        else if (c_size / 2 - position >= 0)
        {
            Node1<T> *previous = head;

            for (int i = 0; i < position - 1; ++i)
            {
                previous = previous->next;
            }

            Node1<T> *follow = previous->next;
            previous->next = follow->next;
            delete follow;
            c_size--;
        }
        else
        {
            Node1<T> *follow = tail;
            for (int i = c_size - 1; i > position + 1; --i)
            {
                follow = follow->prev;
            }
            Node1<T> *previous = follow->prev;
            follow->prev = previous->prev;
            previous->prev->next = follow;
            delete previous;
            c_size--;
        }
    }

    T &operator[](int position) const override
    {
        if (c_size / 2 - position >= 0)
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
        }
        else
        {
            int count = c_size;
            Node1<T> *tmp = tail;
            while (tmp->prev != nullptr)
            {
                if (count == position + 1)
                {
                    return tmp->data;
                }
                tmp = tmp->prev;
                count--;
            }
        }
    }

    void show() override
    {
        Node1<T> *tmp = head;
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
        return "doubly_list_container";
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
    Node1<T> *tail;
};