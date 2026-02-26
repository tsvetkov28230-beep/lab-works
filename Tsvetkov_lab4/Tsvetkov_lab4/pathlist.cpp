#include "PathList.h"
#include <iostream>

PathList::PathList() : paths(nullptr), size(0), capacity(0) {}

PathList::~PathList() {
    clear();
    delete[] paths;
}

PathList::PathList(const PathList& other) : paths(nullptr), size(0), capacity(0) {
    *this = other;
}

PathList& PathList::operator=(const PathList& other) {
    if (this != &other) {
        clear();
        delete[] paths;
        size = other.size;
        capacity = other.capacity;
        paths = new Path * [capacity];
        for (int i = 0; i < size; i++) {
            paths[i] = other.paths[i]->copy();
        }
    }
    return *this;
}

void PathList::resize(int newCapacity) {
    if (newCapacity <= capacity) return;

    Path** newPaths = new Path * [newCapacity];
    for (int i = 0; i < size; i++) {
        newPaths[i] = paths[i];
    }
    delete[] paths;
    paths = newPaths;
    capacity = newCapacity;
}

void PathList::addPath(Path* path) {
    if (size >= capacity) {
        resize(capacity == 0 ? 4 : capacity * 2);
    }
    paths[size++] = path->copy();
}

void PathList::clear() {
    for (int i = 0; i < size; i++) {
        delete paths[i];
    }
    size = 0;
}

int PathList::getSize() const {
    return size;
}

Path* PathList::getPath(int index) const {
    return paths[index];
}

void PathList::printAll() const {
    for (int i = 0; i < size; i++) {
        paths[i]->print();
    }
}