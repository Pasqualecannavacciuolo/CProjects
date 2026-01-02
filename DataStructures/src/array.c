#include "array.h"

int array_init(Array *array, size_t capacity)
{
    if (!array || capacity == 0)
        return -EINVAL;

    array->data = malloc(sizeof(int) * capacity);
    if (!array->data)
        return -ENOMEM;

    array->size = 0;
    array->capacity = capacity;
    return 0;
}

void array_free(Array *array)
{
    if (!array)
        return;

    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

int array_append(Array *array, int value)
{
    if (!array)
        return -EINVAL;

    if (array->size == array->capacity)
    {
        size_t new_capacity = array->capacity * 2;
        int *new_data = realloc(array->data,
                                new_capacity * sizeof(int));
        if (!new_data)
            return -ENOMEM;

        array->data = new_data;
        array->capacity = new_capacity;
    }

    array->data[array->size++] = value;
    return 0;
}

int array_get(Array *array, size_t index, int *out)
{
    if (!array)
        return -EINVAL;

    if (index >= array->size)
    {
        return -ERANGE;
    }

    *out = array->data[index];

    return 0;
}

int array_set(Array *array, size_t index, int value)
{
    if (!array)
        return -EINVAL;

    if (index >= array->size)
    {
        return -ERANGE;
    }

    array->data[index] = value;

    return 0;
}

int array_insert(Array *array, int value, size_t index)
{
    if (!array)
    {
        return -EINVAL;
    }

    if (index > array->size)
    {
        return -ERANGE;
    }

    if (array->size == array->capacity)
    {
        size_t new_capacity = array->capacity ? array->capacity * 2 : 1;
        int *new_data = realloc(array->data, new_capacity * sizeof(int));
        if (!new_data)
        {
            return -ENOMEM;
        }

        array->data = new_data;
        array->capacity = new_capacity;
    }

    if (index < array->size)
    {
        memmove(&array->data[index + 1], &array->data[index], (array->size - index) * sizeof(int));
    }

    array->data[index] = value;
    array->size++;

    return 0;
}

int array_remove(Array *array, size_t index)
{
    if (!array)
    {
        return -EINVAL;
    }

    if (index >= array->size)
    {
        return -ERANGE;
    }

    if (index < array->size - 1)
    {
        memmove(&array->data[index],
                &array->data[index + 1],
                (array->size - index - 1) * sizeof(int));
    }

    array->size--;

    return 0;
}

size_t array_size(Array *array)
{
    if (!array)
    {
        return -EINVAL;
    }

    return array->size;
}

size_t array_capacity(Array *array)
{
    if (!array)
    {
        return -EINVAL;
    }

    return array->capacity;
}

void array_print(Array *array)
{
    if (!array)
    {
        fprintf(stderr, "No array to print.\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < array->size; i++)
    {
        printf("%d", array->data[i]);
        if (i < array->size - 1)
            printf(", ");
    }
    printf("]\n");
}
