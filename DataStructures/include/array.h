#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

/**
 * struct array - Dynamic array of integers
 *
 * @data:     Pointer to the contiguous memory storing the elements
 * @size:     Number of elements currently stored in the array
 * @capacity: Total number of elements that can be stored without resizing
 *
 * This structure represents a dynamically resizable array of integers.
 * Memory ownership is explicit: the caller is responsible for calling
 * array_free() once the array is no longer needed.
 *
 * The structure itself does not perform any I/O and does not manage
 * its own lifetime implicitly.
 */
struct array
{
    int *data;       /**< Pointer to the elements of the array */
    size_t size;     /**< Number of items actually present */
    size_t capacity; /**< Maximum number of elements allocated */
};

typedef struct array Array;

/**
 * array_init - Initialize a dynamic array
 * @array:    Pointer to an already allocated Array structure
 * @capacity: Initial number of elements that can be stored
 *
 * Allocates internal storage for the array and initializes its state.
 *
 * Return: 0 on success,
 *         -EINVAL if capacity is zero or parameters are invalid,
 *         -ENOMEM if memory allocation fails.
 *
 * Note: This function does not allocate the Array structure itself.
 *       The caller owns the structure and is responsible for freeing
 *       it with array_free().
 */
int array_init(Array *array, size_t capacity);

/**
 * array_free - Release resources associated with an array
 * @array: Pointer to the array to be released
 *
 * Frees the internal data buffer associated with the array.
 * The Array structure itself is not freed.
 *
 * After this call, the contents of @array are no longer valid.
 */
void array_free(Array *array);

/**
 * array_get - Retrieve an element from the array
 * @array: Pointer to the array
 * @index: Index of the element to retrieve
 * @out:   Pointer where the retrieved value will be stored
 *
 * Retrieves the element at the specified index.
 *
 * Return: 0 on success,
 *         -EINVAL if parameters are invalid,
 *         -ERANGE if index is out of bounds.
 */
int array_get(Array *array, size_t index, int *out);

/**
 * array_set - Overwrite an element in the array
 * @array: Pointer to the array
 * @index: Index of the element to modify
 * @value: New value to store
 *
 * Replaces the value at the specified index.
 *
 * Return: 0 on success,
 *         -EINVAL if parameters are invalid,
 *         -ERANGE if index is out of bounds.
 */
int array_set(Array *array, size_t index, int value);

/**
 * array_append - Append an element to the end of the array
 * @array: Pointer to the array
 * @value: Value to append
 *
 * Appends a new element at the end of the array. If the internal
 * buffer is full, the function grows the capacity, typically by
 * reallocating a larger buffer.
 *
 * Return: 0 on success,
 *         -EINVAL if the array pointer is invalid,
 *         -ENOMEM if memory reallocation fails.
 */
int array_append(Array *array, int value);

/**
 * array_size - Get the number of stored elements
 * @array: Pointer to the array
 *
 * Return: Number of elements currently stored in the array.
 */
size_t array_size(Array *array);

/**
 * array_capacity - Get the allocated capacity of the array
 * @array: Pointer to the array
 *
 * Return: Total number of elements that can be stored without resizing.
 */
size_t array_capacity(Array *array);

void array_print(Array *array);

#endif
