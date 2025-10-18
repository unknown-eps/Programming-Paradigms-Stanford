/*
In cpp you can use templates.
This is on how this is done in C.
*/
#include <iostream>
#include <cstring>
struct frac
{
    int num;
    int den;
};
void *lsearch(void *key, void *base, int n, int elemsize)
{
    for (int i = 0; i < n; i++)
    {
        char *start_address = (char *)base + elemsize * i;
        if (memcmp(start_address, key, elemsize) == 0)
        {
            return (void *)start_address;
        }
    }
    return NULL;
}
int main()
{
    struct frac key;
    key.num = 100;
    key.den = 200;

    struct frac arr1[2];
    arr1[0].num = 50;
    arr1[0].den = 100;
    arr1[1].num = 75;
    arr1[1].den = 150;

    struct frac arr2[2];
    arr2[0].num = 30;
    arr2[0].den = 60;
    arr2[1].num = 100;
    arr2[1].den = 200;

    // Search in arr1
    struct frac *result1 = (struct frac *)lsearch(&key, arr1, 2, sizeof(struct frac));
    if (result1 != NULL)
    {
        std::cout << "Found in arr1: " << result1->num << "/" << result1->den << std::endl;
    }
    else
    {
        std::cout << "Not found in arr1" << std::endl;
    }

    // Search in arr2
    struct frac *result2 = (struct frac *)lsearch(&key, arr2, 2, sizeof(struct frac));
    if (result2 != NULL)
    {
        std::cout << "Found in arr2: " << result2->num << "/" << result2->den << std::endl;
    }
    else
    {
        std::cout << "Not found in arr2" << std::endl;
    }
}