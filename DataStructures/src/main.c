#include <stdio.h>
#include "array.h"

int main(void)
{
    Array array;
    int ret, value;
    int values[] = {99, 98, 97, 96};

    ret = array_init(&array, 10);
    if (ret)
        goto out;

    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); i++)
    {
        ret = array_append(&array, values[i]);
        if (ret)
            goto out;
    }

    array_print(&array);

    int index = 2;
    ret = array_get(&array, index, &value);
    if (ret == 0)
        printf("Value = %d at index[%d]\n", value, index);
    else
        goto out;

    ret = array_set(&array, index, 0);
    if (ret == 0)
        array_print(&array);
    else
        goto out;

out:
    array_free(&array);
    return ret;
}
