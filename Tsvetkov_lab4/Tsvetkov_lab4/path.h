#pragma once

class Path {
private:
    int* values;
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    Path();
    ~Path();
    Path(const Path& other);
    Path& operator=(const Path& other);

    void addValue(int value);
    void removeLast();
    int getSum() const;
    void print() const;
    int* getValues() const;
    int getSize() const;
    Path* copy() const;
};