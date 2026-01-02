#include <stdio.h>
#include "array.h"
#include "array_algo.h"

// funzione cmp crescente
int cmp_asc(int a, int b)
{
    return a - b; // <0 se a < b
}

// funzione cmp decrescente
int cmp_desc(int a, int b)
{
    return b - a; // <0 se a > b
}

int main(void)
{
    Array array;
    int ret, value;
    size_t search_index;
    // int values[] = {
    //     42, 87, 13, 99, 5, 64, 21, 78, 56, 9,
    //     91, 34, 7, 68, 50, 26, 83, 15, 97, 39,
    //     2, 71, 58, 44, 19, 90, 31, 66, 11, 84,
    //     53, 24, 76, 1, 60, 35, 92, 48, 17, 70,
    //     28, 81, 6, 55, 95, 37, 63, 10, 88, 22,
    //     74, 4, 59, 32, 86, 14, 69, 41, 98, 27,
    //     65, 20, 80, 46, 12, 93, 29, 57, 73, 18,
    //     85, 33, 61, 8, 94, 49, 16, 75, 40, 89,
    //     25, 67, 3, 82, 51, 96, 36, 72, 54, 30};
    int values[] = {42, 87, 13, 99, 5, 64, 21, 78, 56, 9};

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
    printf("Array capacity: %zu\n", array_capacity(&array));
    printf("Array size: %zu\n", array_size(&array));

    ret = array_insert(&array, 88, 6);
    if (ret == 0)
    {
        array_print(&array);
        printf("Array capacity: %zu\n", array_capacity(&array));
        printf("Array size: %zu\n", array_size(&array));
    }
    else
    {

        goto out;
    }

    ret = array_remove(&array, 6);
    if (ret == 0)
    {
        array_print(&array);
        printf("Array capacity: %zu\n", array_capacity(&array));
        printf("Array size: %zu\n", array_size(&array));
    }
    else
    {

        goto out;
    }

    /*int index = 2;
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

    ret = array_sort(&array, cmp_asc);
    if (ret == 0)
    {
        printf("Array Sorted with - Bubble Sort\n");
        array_print(&array);
    }
    else
        goto out;

    ret = array_linear_search(&array, 72, &search_index);
    if (ret == 0)
    {
        printf("Element %d founded at index %zu\n", 72, search_index);
        array_print(&array);
    }
    else
        goto out;

    ret = array_binary_search(&array, 37, &search_index);
    if (ret == 0)
    {
        printf("Element %d founded at index %zu\n", 37, search_index);
        array_print(&array);
    }
    else
        goto out;*/

out:
    array_free(&array);
    return ret;
}
