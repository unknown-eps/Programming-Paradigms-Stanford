#include <cstring>
int compare_chars(void *arg1, void *arg2)
{
    return strcmp((char *)arg1, (char *)arg2);
}