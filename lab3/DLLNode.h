#pragma once

template <class T>
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = nullptr;
    }
    DLLNode(const T &el, DLLNode<T> *n = nullptr, DLLNode<T> *p = nullptr)
    {
        data = el;
        next = n;
        prev = p;
    }
    T data;
    DLLNode<T> *prev, *next;
};