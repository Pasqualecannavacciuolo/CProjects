#include "array_algo.h"

/*--------------------------------------------------
 * Sort function: Bubble Sort
 *-------------------------------------------------*/
int array_sort(Array *array, array_cmp_fn cmp)
{
    if (!array || !cmp)
    {
        return -EINVAL;
    }

    // Already sorted
    if (array->size < 2)
    {
        return 0;
    }

    for (size_t i = 0; i < array->size - 1; i++)
    {
        for (size_t j = 0; j < array->size - i - 1; j++)
        {
            if (cmp(array->data[j], array->data[j + 1]) > 0)
            {
                int tmp = array->data[j];
                array->data[j] = array->data[j + 1];
                array->data[j + 1] = tmp;
            }
        }
    }
    return 0;
}

/*--------------------------------------------------
 * Search function: Linear Search
 *-------------------------------------------------*/
int array_linear_search(const Array *array, int value, size_t *index)
{
    if (!array || !index)
    {
        return -EINVAL;
    }

    for (size_t i = 0; i < array->size; i++)
    {
        if (array->data[i] == value)
        {
            *index = i;
            return 0;
        }
    }
    return -ERANGE;
}

/*--------------------------------------------------
 * Search function: Binary Search
 *-------------------------------------------------*/
int array_binary_search(const Array *array, int value, size_t *index)
{
    if (!array || !index)
        return -EINVAL;

    size_t left = 0;
    size_t right = array->size;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (array->data[mid] == value)
        {
            *index = mid;
            return 0;
        }

        if (array->data[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return -ERANGE;
}
