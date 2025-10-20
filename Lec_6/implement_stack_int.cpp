#include <stdlib.h>
#include "implement_stack_int.h"
#include <cassert>
#define INITIAL_CAPACITY 4
/*
When using free in cpp we do not need to provide the number of bytes as the malloc call keeps track of that?
If these were string literals then dispose function would need to dispose of the space needed to store them as well.
realloc takes input malloc output and the size in bytes to resize it. Also frees appropriately the initial memory.
One important advantage is that if alternate space is available it just uses it so better to use than manual doing thigs.
Realloc with NULL uses malloc can be used for consistency in programs.
If size given to realloc is smaller then current size then it does not do anything.
*/
void StackNew(stack *s)
{
    s->logicallen = 0;
    s->alloclength = INITIAL_CAPACITY;
    s->elems = (int *)realloc(NULL, INITIAL_CAPACITY * sizeof(int));
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);
}

void StackPush(stack *s, int value)
{
    if (s->alloclength == s->logicallen)
    {
        s->alloclength = 2 * s->alloclength;
        s->elems = (int *)realloc(s->elems, sizeof(int) * s->alloclength);
        assert(s->elems != NULL);
    }
    s->elems[s->logicallen] = value;
    (s->logicallen)++;
}

int StackPop(stack *s)
{
    if (s->logicallen != 0)
    {
        s->logicallen--;
    }
    return s->elems[s->logicallen];
}