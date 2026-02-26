#include <chrono>﻿
#include <cstdint>
#include <iostream>

using std::swap;
using std::rand;
using std::cout;
using std::endl;

using std::chrono::steady_clock;

void bubbleSort(int arr[], int len)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int piv = partition(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}

int linearSearch(int arr[], int len, int value)
{
    int index = -1;
    bool is_not_found = true;
    while (index < len && is_not_found)
    {
        if (arr[index++] == value)
        {
            is_not_found = false;
        }
    }
    if (index >= len)
    {
        index = -1;
    }
    return index;
}


int binarySearch(int arr[], int len, int value)
{
    int left = 0;
    int right = len - 1;
    bool is_not_found = true;
    int index{ 0 };

    while (left <= right && is_not_found)
    {
        index = left + (right - left) / 2;

        if (arr[index] == value)
        {
            is_not_found = false;
        }
        else if (arr[index] < value)
        {
            left = index + 1;
        }
        else
        {
            right = index - 1;
        }
    }
    if (is_not_found)
    {
        index = -1;
    }
    return index;
}

int random()
{
    return rand() % 1000000;
}

void fillRandom(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = random();
    }
}

int duration(int(*search)(int[], int, int), int arr[], int len, int value)
{
    steady_clock::time_point start = steady_clock::now();
    search(arr, len, value);
    steady_clock::time_point end = steady_clock::now();
    return int((end - start).count());
}

int duration(void(*sort)(int[], int, int), int arr[], int len)
{
    steady_clock::time_point start = steady_clock::now();
    sort(arr, 0, len - 1);
    steady_clock::time_point end = steady_clock::now();
    return int(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}

int duration(void(*sort)(int[], int), int arr[], int len)
{
    steady_clock::time_point start = steady_clock::now();
    sort(arr, len);
    steady_clock::time_point end = steady_clock::now();
    return int(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}


int main()
{
    int* arr, len, linear, binary;
    int64_t bubble, quick;
    cout << "bubble\tquick\tlinear\tbinary\n";
    for (int i = 3; i <= 16; i++)
    {
        bubble = quick = linear = binary = 0;
        for (int j = 0; j < 10; j++)
        {
            len = int(pow(2, i));
            arr = new (int[len]);

            fillRandom(arr, len);
            bubble += duration(bubbleSort, arr, len);

            fillRandom(arr, len);
            linear += duration(linearSearch, arr, len, random());
            quick += duration(quickSort, arr, len);
            binary += duration(binarySearch, arr, len, random());
        }
        cout << bubble / 10 << "\t" << quick / 10 << "\t" << linear / 10 << "\t" << binary / 10 << "\n";
        delete[] arr;
    }
    return 0;
}
