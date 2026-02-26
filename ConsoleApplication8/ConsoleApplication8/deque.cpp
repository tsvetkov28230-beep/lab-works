#include "Deque.h"
#include <stdexcept>

template<typename T>
Deque<T>::Deque()
{
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    count = new size_type(0);
}

template<typename T>
Deque<T>::Deque(const value_type& item, size_type n) : Deque()
{
    for (size_type i = 0; i < n; ++i)
        pushBack(item);
}

template<typename T>
Deque<T>::Deque(const Deque& other) : Deque()
{
    copyFrom(other);
}

template<typename T>
Deque<T>::~Deque()
{
    clear();
    delete head;
    delete tail;
    delete count;
}

template<typename T>
void Deque<T>::copyFrom(const Deque& other)
{
    Node* otherCurrent = other.head->next;
    while (otherCurrent != other.tail)
    {
        pushBack(*(otherCurrent->data));
        otherCurrent = otherCurrent->next;
    }
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
void Deque<T>::clear()
{
    while (!isEmpty())
        popFront();
}

template<typename T>
typename Deque<T>::value_type& Deque<T>::front()
{
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    return *(head->next->data);
}

template<typename T>
const typename Deque<T>::value_type& Deque<T>::front() const
{
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    return *(head->next->data);
}

template<typename T>
typename Deque<T>::value_type& Deque<T>::back()
{
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    return *(tail->prev->data);
}

template<typename T>
const typename Deque<T>::value_type& Deque<T>::back() const
{
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    return *(tail->prev->data);
}

template<typename T>
bool Deque<T>::isEmpty() const
{
    return *count == 0;
}

template<typename T>
typename Deque<T>::size_type Deque<T>::size() const
{
    return *count;
}

template<typename T>
void Deque<T>::pushFront(const value_type& item)
{
    Node* newNode = new Node(item, head, head->next);
    head->next->prev = newNode;
    head->next = newNode;
    ++(*count);
}

template<typename T>
void Deque<T>::pushBack(const value_type& item)
{
    Node* newNode = new Node(item, tail->prev, tail);
    tail->prev->next = newNode;
    tail->prev = newNode;
    ++(*count);
}

template<typename T>
void Deque<T>::popFront()
{
    if (isEmpty())
        throw std::out_of_range("Deque is empty");

    Node* toDelete = head->next;
    head->next = toDelete->next;
    toDelete->next->prev = head;
    delete toDelete;
    --(*count);
}

template<typename T>
void Deque<T>::popBack()
{
    if (isEmpty())
        throw std::out_of_range("Deque is empty");

    Node* toDelete = tail->prev;
    tail->prev = toDelete->prev;
    toDelete->prev->next = tail;
    delete toDelete;
    --(*count);
}