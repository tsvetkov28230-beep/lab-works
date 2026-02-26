#pragma once

#include <cstddef>
#include <stdexcept>

template<typename T>
class Deque
{
public:
    typedef T value_type;
    typedef std::size_t size_type;

    Deque()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        count = new size_type(0);
    }

    Deque(const value_type& item, size_type n = 1) : Deque()
    {
        for (size_type i = 0; i < n; ++i)
            pushBack(item);
    }

    Deque(const Deque& other) : Deque()
    {
        copyFrom(other);
    }

    virtual ~Deque()
    {
        clear();
        delete head;
        delete tail;
        delete count;
    }

    Deque& operator=(const Deque& other)
    {
        if (this != &other)
        {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    value_type& front()
    {
        if (isEmpty())
            throw std::out_of_range("Deque is empty");
        return *(head->next->data);
    }

    const value_type& front() const
    {
        if (isEmpty())
            throw std::out_of_range("Deque is empty");
        return *(head->next->data);
    }

    value_type& back()
    {
        if (isEmpty())
            throw std::out_of_range("Deque is empty");
        return *(tail->prev->data);
    }

    const value_type& back() const
    {
        if (isEmpty())
            throw std::out_of_range("Deque is empty");
        return *(tail->prev->data);
    }

    bool isEmpty() const
    {
        return *count == 0;
    }

    size_type size() const
    {
        return *count;
    }

    void pushFront(const value_type& item)
    {
        Node* newNode = new Node(item, head, head->next);
        head->next->prev = newNode;
        head->next = newNode;
        ++(*count);
    }

    void pushBack(const value_type& item)
    {
        Node* newNode = new Node(item, tail->prev, tail);
        tail->prev->next = newNode;
        tail->prev = newNode;
        ++(*count);
    }

    void popFront()
    {
        if (isEmpty())
            throw std::out_of_range("Deque is empty");

        Node* toDelete = head->next;
        head->next = toDelete->next;
        toDelete->next->prev = head;
        delete toDelete;
        --(*count);
    }

    void popBack()
    {
        if (isEmpty())
            throw std::out_of_range("Deque is empty");

        Node* toDelete = tail->prev;
        tail->prev = toDelete->prev;
        toDelete->prev->next = tail;
        delete toDelete;
        --(*count);
    }

    friend std::ostream& operator<<(std::ostream& os, const Deque& dq)
    {
        size_t sz = dq.size();
        os << sz;
        for (Node* p = dq.head; p; p->next) {
            os << " " << p->data;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Deque& dq)
    {
        dq.clear();
        size_t sz = 0;
        T value;
        is >> sz;
        for (auto i = 0; i < sz; i++) {
            is >> value;
            dq.pushBack(value);
        }
        return is;
    }


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

    void copyFrom(const Deque& other)
    {
        Node* otherCurrent = other.head->next;
        while (otherCurrent != other.tail)
        {
            pushBack(*(otherCurrent->data));
            otherCurrent = otherCurrent->next;
        }
    }

    void clear()
    {
        while (!isEmpty())
            popFront();
    }
};