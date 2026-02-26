#include "local.h"

MyDeque::MyDeque() {
    capacity = 10;
    data = new int[capacity];
    size = 0;
    frontIndex = 0;
    backIndex = 0;
}

MyDeque::MyDeque(int initialCapacity) {
    if (initialCapacity <= 0) {
        initialCapacity = 10;
    }
    capacity = initialCapacity;
    data = new int[capacity];
    size = 0;
    frontIndex = 0;
    backIndex = 0;
}

MyDeque::~MyDeque() {
    delete[] data;
}

void MyDeque::resize(int newCapacity) {
    if (newCapacity <= capacity) {
        return;
    }

    int* newData = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[(frontIndex + i) % capacity];
    }

    delete[] data;
    data = newData;
    frontIndex = 0;
    backIndex = size - 1;
    capacity = newCapacity;
}

void MyDeque::push_back(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    if (size == 0) {
        data[0] = value;
        frontIndex = 0;
        backIndex = 0;
    }
    else {
        backIndex = (backIndex + 1) % capacity;
        data[backIndex] = value;
    }

    size++;
}

void MyDeque::push_front(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    if (size == 0) {
        data[0] = value;
        frontIndex = 0;
        backIndex = 0;
    }
    else {
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = value;
    }

    size++;
}

void MyDeque::pop_back() {
    if (size == 0) {
        return;
    }

    if (size == 1) {
        frontIndex = 0;
        backIndex = 0;
    }
    else {
        backIndex = (backIndex - 1 + capacity) % capacity;
    }

    size--;
}

void MyDeque::pop_front() {
    if (size == 0) {
        return;
    }

    if (size == 1) {
        frontIndex = 0;
        backIndex = 0;
    }
    else {
        frontIndex = (frontIndex + 1) % capacity;
    }

    size--;
}

int MyDeque::front() const {
    if (size == 0) {
        return 0;
    }
    return data[frontIndex];
}

int MyDeque::back() const {
    if (size == 0) {
        return 0;
    }
    return data[backIndex];
}

bool MyDeque::empty() const {
    return size == 0;
}

int MyDeque::getSize() const {
    return size;
}

int MyDeque::at(int index) const {
    if (index < 0 || index >= size) {
        return 0;
    }
    return data[(frontIndex + index) % capacity];
}

LocalExtremums::LocalExtremums(int k) {
    if (k <= 0) {
        windowSize = 1;
    }
    else {
        windowSize = k;
    }
}

void LocalExtremums::add(const int nums[], int index) {
    while (!minIndices.empty() && nums[minIndices.back()] >= nums[index]) {
        minIndices.pop_back();
    }
    minIndices.push_back(index);

    while (!maxIndices.empty() && nums[maxIndices.back()] <= nums[index]) {
        maxIndices.pop_back();
    }
    maxIndices.push_back(index);
}

void LocalExtremums::removeOld(int currentIndex) {
    int leftBound = currentIndex - windowSize;

    while (!minIndices.empty() && minIndices.front() <= leftBound) {
        minIndices.pop_front();
    }

    while (!maxIndices.empty() && maxIndices.front() <= leftBound) {
        maxIndices.pop_front();
    }
}

int LocalExtremums::getMin(const int nums[]) const {
    if (minIndices.empty()) {
        return 0;
    }
    return nums[minIndices.front()];
}

int LocalExtremums::getMax(const int nums[]) const {
    if (maxIndices.empty()) {
        return 0;
    }
    return nums[maxIndices.front()];
}

bool LocalExtremums::isEmpty() const {
    return minIndices.empty() && maxIndices.empty();
}

int LocalExtremums::getWindowSize() const {
    return windowSize;
}