#pragma once

#include "IContainers.hpp"

template <typename T>
class Node
{
public:
    Node *next;
    Node *prev;
    T data;
};

template <typename T>
class list_container : public IContainers<T>
{

private:
    int size;
};