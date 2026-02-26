#include "Path.h"
#include <iostream>

Path::Path() : values(nullptr), size(0), capacity(0) {}

Path::~Path() {
    delete[] values;
}

Path::Path(const Path& other) : values(nullptr), size(0), capacity(0) {
    *this = other;
}

Path& Path::operator=(const Path& other) {
    if (this != &other) {
        delete[] values;
        size = other.size;
        capacity = other.capacity;
        values = new int[capacity];
        for (int i = 0; i < size; i++) {
            values[i] = other.values[i];
        }
    }
    return *this;
}

void Path::resize(int newCapacity) {
    if (newCapacity <= capacity) return;

    int* newValues = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newValues[i] = values[i];
    }
    delete[] values;
    values = newValues;
    capacity = newCapacity;
}

void Path::addValue(int value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 4 : capacity * 2);
    }
    values[size++] = value;
}

void Path::removeLast() {
    if (size > 0) {
        size--;
    }
}

int Path::getSum() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum;
}

void Path::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << values[i];
        if (i < size - 1) {
            std::cout << " > ";
        }
    }
    std::cout << std::endl;
}

int* Path::getValues() const {
    return values;
}

int Path::getSize() const {
    return size;
}

Path* Path::copy() const {
    Path* newPath = new Path();
    for (int i = 0; i < size; i++) {
        newPath->addValue(values[i]);
    }
    return newPath;
}