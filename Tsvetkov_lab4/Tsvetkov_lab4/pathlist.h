#pragma once

#include "Path.h"

class PathList {
private:
    Path** paths;
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    PathList();
    ~PathList();
    PathList(const PathList& other);
    PathList& operator=(const PathList& other);

    void addPath(Path* path);
    void clear();
    int getSize() const;
    Path* getPath(int index) const;
    void printAll() const;
};