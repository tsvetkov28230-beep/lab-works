#pragma once

#include <cstddef>
#include <stdexcept>
#include <iostream>

template<typename T>
class List
{
private:
    struct Node
    {
        T* data;
        Node* prev;
        Node* next;

        Node(const T& d = T(), Node* p = nullptr, Node* n = nullptr)
            : prev(p), next(n)
        {
            data = new T(d);
        }

        ~Node()
        {
            delete data;
        }
    };

public:
    class Iterator;
    typedef T value_type;
    typedef std::size_t size_type;

    List()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        count = new size_type(0);
    }

    List(const value_type& item, size_type n = 1) : List()
    {
        for (size_type i = 0; i < n; ++i)
            pushBack(item);
    }

    List(const List& other) : List()
    {
        copyFrom(other);
    }

    ~List()
    {
        clear();
        delete head;
        delete tail;
        delete count;
    }

    List& operator=(const List& other)
    {
        if (this != &other)
        {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    Iterator begin() { return Iterator(head->next); }
    Iterator end() { return Iterator(tail); }

    bool empty() const { return *count == 0; }
    size_type size() const { return *count; }

    void pushFront(const value_type& item)
    {
        insert(begin(), item);
    }

    void pushBack(const value_type& item)
    {
        insert(end(), item);
    }

    void popFront()
    {
        erase(begin());
    }

    void popBack()
    {
        Iterator it = end();
        --it;
        erase(it);
    }

    Iterator insert(Iterator pos, const value_type& item)
    {
        Node* current = pos.current;
        Node* newNode = new Node(item, current->prev, current);
        current->prev->next = newNode;
        current->prev = newNode;
        ++(*count);
        return Iterator(newNode);
    }

    Iterator erase(Iterator pos)
    {
        if (pos == end())
            throw std::out_of_range("Cannot erase end iterator");

        Node* toDelete = pos.current;
        Node* nextNode = toDelete->next;
        toDelete->prev->next = nextNode;
        nextNode->prev = toDelete->prev;
        delete toDelete;
        --(*count);
        return Iterator(nextNode);
    }

    void splice(List& other)
    {
        if (other.empty()) return;

        tail->prev->next = other.head->next;
        other.head->next->prev = tail->prev;
        tail->prev = other.tail->prev;
        other.tail->prev->next = tail;

        *count += *other.count;
        *other.count = 0;

        other.head->next = other.tail;
        other.tail->prev = other.head;
    }

    void merge(List& other)
    {
        Iterator it1 = begin();
        Iterator it2 = other.begin();

        while (it1 != end() && it2 != other.end())
        {
            if (*it2 < *it1)
            {
                Node* node = it2.current;
                ++it2;

                node->prev->next = node->next;
                node->next->prev = node->prev;

                node->prev = it1.current->prev;
                node->next = it1.current;
                it1.current->prev->next = node;
                it1.current->prev = node;

                ++(*count);
                --(*other.count);
            }
            else
            {
                ++it1;
            }
        }

        if (it2 != other.end())
        {
            tail->prev->next = other.head->next;
            other.head->next->prev = tail->prev;
            tail->prev = other.tail->prev;
            other.tail->prev->next = tail;

            *count += *other.count;
            *other.count = 0;
        }

        other.head->next = other.tail;
        other.tail->prev = other.head;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& lst)
    {
        os << "[";
        Node* current = lst.head->next;
        bool first = true;
        while (current != lst.tail)
        {
            if (!first) os << " ";
            os << *(current->data);
            first = false;
            current = current->next;
        }
        os << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, List& lst)
    {
        lst.clear();
        value_type val;
        while (is >> val)
        {
            lst.pushBack(val);
        }
        is.clear();
        return is;
    }

    class Iterator
    {
    private:
        Node* current;

    public:
        Iterator(Node* node = nullptr) : current(node) {}

        value_type& operator*() { return *(current->data); }
        value_type* operator->() { return current->data; }

        Iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            current = current->next;
            return temp;
        }

        Iterator& operator--()
        {
            current = current->prev;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            current = current->prev;
            return temp;
        }

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }

        friend class List;
    };

private:
    Node* head;
    Node* tail;
    size_type* count;

    void copyFrom(const List& other)
    {
        Node* current = other.head->next;
        while (current != other.tail)
        {
            pushBack(*(current->data));
            current = current->next;
        }
    }

    void clear()
    {
        while (!empty())
            popFront();
    }
};