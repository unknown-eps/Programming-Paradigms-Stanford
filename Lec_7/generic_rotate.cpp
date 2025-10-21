#include <cstring>
#include <iostream>
#include "generic_rotate.h"
/*
memcpy can be used only when sorce and dest have not overlap
Otherwise use memmove.
Here end points one past the last elemnet that is at thenext un-occupied space. [start,end) is occupied
*/
void rotate(void *start, void *mid, void *end, int elemsize)
{
    int front_size = (char *)mid - (char *)start;
    int back_size = (char *)end - (char *)mid;
    char buffer[front_size];
    memcpy(buffer, start, front_size);
    memmove(start, mid, back_size);
    memcpy((char *)end - front_size, buffer, front_size);
}
