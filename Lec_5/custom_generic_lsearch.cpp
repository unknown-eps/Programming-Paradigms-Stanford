/*
This allows the user to define a custom comparator function
Note that void* cannot be dereferenced or used in pointer arithmetic but we can use void** in both derefrencing and pointer arithmetic.
*/
#include <iostream>
#include <cstring>
#include "compare_implement_for_char.h"
// Comparator function for char*
int compare_chars(void *arg1, void *arg2);

void *lsearch(void *key, void *base, int n, int elemsize, int (*cmp)(void *, void *))
{
    for (int i = 0; i < n; i++)
    {
        void *start_add = (char *)base + i * elemsize;
        if (cmp(start_add, key) == 0) // (*cmp)(start_add,key) also works. These are examples of function decay.
        {
            return start_add;
        }
    }
    return NULL;
}

int main()
{
    // Create an array of char* for demonstration
    const char *fruits[] = {
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry"};

    int num_fruits = sizeof(fruits) / sizeof(fruits[0]);
    int elem_size = sizeof(char *);

    // Search for "cherry"
    const char *search_key = "cherry";
    const char **result = (const char **)lsearch((void *)&search_key, (void *)fruits, num_fruits, elem_size, compare_chars);// &compare_chars also works

    if (result != NULL)
    {
        std::cout << "Found: " << *result << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    // Search for "grape" (not in the array)
    const char *search_key2 = "grape";
    const char **result2 = (const char **)lsearch((void *)&search_key2, (void *)fruits, num_fruits, elem_size, compare_chars);

    if (result2 != NULL)
    {
        std::cout << "Found: " << *result2 << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}