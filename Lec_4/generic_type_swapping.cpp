/*
In cpp you can use templates.
This is on how this is done in C.

Advantage over cpp templates:
in cpp templates for each data-type new assembly code has to be made.(Increases executable size.)
Our version of swap works for all possible data-types with one assembly code.
However in case or erros our code fails silently.
*/
#include <iostream>
#include <cstring>

void swap(void *ptr1, void *ptr2, int size)
{
    char buffer[size];
    for (int i = 0; i < size; i++)
    {
        buffer[i] = ((char *)(ptr2))[i];
        ((char *)(ptr2))[i] = ((char *)(ptr1))[i];
        ((char *)(ptr1))[i] = buffer[i];
    }
}

void swap_memcpy(void *ptr1, void *ptr2, int size)
{
    char buffer[size]; // Some cpp compilers may not allow dynamic sized arrays.
    memcpy(buffer, ptr2, size);
    memcpy(ptr2, ptr1, size);
    memcpy(ptr1, buffer, size);
}

int main()
{
    int x = 100;
    int y = 2;
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    swap(&x, &y, sizeof(x));
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';
    swap_memcpy(&x, &y, sizeof(x));
    std::cout << "After swap_memcpy: x = " << x << ", y = " << y << '\n';
    
    return 0;
}