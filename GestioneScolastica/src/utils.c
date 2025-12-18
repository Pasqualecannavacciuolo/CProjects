#include "utils.h"

char *dup_string(const char *s)
{
    char *copy = malloc(strlen(s) + 1);
    if (copy)
        strcpy(copy, s);
    return copy;
}
