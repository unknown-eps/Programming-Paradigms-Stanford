/*
Here we see the effect of trying to place a short inside an int in a array.
Note that this depends on the endiness of the system.
*/
#include<iostream>
int main()
{
    int arr[5];
    arr[3] = 128;
    ((short *)(arr))[6] = 2;
    std::cout<<"New value of arr at index 3 is "<< arr[3] <<std::endl; 
    return 0;
} 