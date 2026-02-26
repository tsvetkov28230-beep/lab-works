#pragma once

class MyDeque {
private:
    int* data;
    int capacity;
    int size;
    int frontIndex;
    int backIndex;

    void resize(int newCapacity);

public:
    MyDeque();
    MyDeque(int initialCapacity);
    ~MyDeque();

    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();

    int front() const;
    int back() const;

    bool empty() const;
    int getSize() const;

    int at(int index) const;
};

class LocalExtremums {
private:
    MyDeque minIndices;
    MyDeque maxIndices;
    int windowSize;

public:
    LocalExtremums(int k);
    void add(const int nums[], int index);
    void removeOld(int currentIndex);
    int getMin(const int nums[]) const;
    int getMax(const int nums[]) const;
    bool isEmpty() const;
    int getWindowSize() const;
};