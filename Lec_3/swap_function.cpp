/*
Swap two integetr values via pointers.
*/
#include <iostream>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
int main()
{
    int a = 0;
    int b = 1;
    swap(&a,&b);
    std::cout << "Value of a and b are " << a << " b is " << b << std::endl;
}