#pragma once

#include <cstddef>

template<typename T>
class Deque
{
public:
    typedef T value_type;
    typedef std::size_t size_type;

    Deque();
    Deque(const value_type& item, size_type n = 1);
    Deque(const Deque& other);
    ~Deque();

    Deque& operator=(const Deque& other);

    value_type& front();
    value_type& back();
    const value_type& front() const;
    const value_type& back() const;

    bool isEmpty() const;
    size_type size() const;

    void pushFront(const value_type& item);
    void pushBack(const value_type& item);
    void popFront();
    void popBack();

private:
    struct Node
    {
        value_type* data;
        Node* prev;
        Node* next;

        Node(const value_type& d = value_type(), Node* p = nullptr, Node* n = nullptr)
            : prev(p), next(n)
        {
            data = new value_type(d);
        }

        ~Node()
        {
            delete data;
        }
    };

    Node* head;
    Node* tail;
    size_type* count;

    void copyFrom(const Deque& other);
    void clear();
};