#include <iostream>
#include <cstring>
#include "generic_rotate.h"

int main()
{
    // Test with integer array
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int elem_size = sizeof(int);

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Rotate the array by specifying the start, mid, and end pointers
    // For example, rotate so that elements from position 3 onwards come first
    // Original: [1, 2, 3, 4, 5, 6, 7]
    // After rotate at position 3: [4, 5, 6, 7, 1, 2, 3]
    int *start = arr;
    int *mid = arr + 3;    // Points to element at index 3 (value 4)
    int *end = arr + size; // Points one past the last element

    rotate(start, mid, end, elem_size);

    std::cout << "Array after rotation: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Another test with different rotation point
    int arr2[] = {10, 20, 30, 40, 50};
    size = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "\nSecond test - Original array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    start = arr2;
    mid = arr2 + 2; // Points to element at index 2 (value 30)
    end = arr2 + size;

    rotate(start, mid, end, elem_size);

    std::cout << "Second test - Array after rotation: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}