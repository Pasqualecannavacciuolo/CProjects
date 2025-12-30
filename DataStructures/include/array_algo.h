#ifndef ARRAY_ALG_H
#define ARRAY_ALG_H

#include "array.h"
#include <stddef.h>

/**
 * typedef array_cmp_fn - Comparison function for sorting
 * @a: first integer to compare
 * @b: second integer to compare
 *
 * Return:
 *   negative if a < b,
 *   0        if a == b,
 *   positive if a > b
 *
 * This function type is used by array_sort to compare two elements.
 */
typedef int (*array_cmp_fn)(int a, int b);

/**
 * array_sort - Sorts the array using the provided comparison function
 * @array: pointer to the array to sort
 * @cmp: comparison function
 *
 * Return:
 *   0       on success
 *   -EINVAL if parameters are invalid
 *
 * Sorting is done in-place and the function does not allocate memory.
 */
int array_sort(Array *array, array_cmp_fn cmp);

/**
 * array_linear_search - Searches for a value in the array using linear search
 * @array: pointer to the array to search
 * @value: value to search for
 * @index: out parameter where the index of the found element will be stored
 *
 * Return:
 *   0       if value is found
 *   -ERANGE if value is not found
 *   -EINVAL if parameters are invalid
 *
 * This search works on unsorted arrays and scans elements sequentially.
 */
int array_linear_search(const Array *array, int value, size_t *index);

/**
 * array_binary_search - Searches for a value in a sorted array using binary search
 * @array: pointer to the sorted array
 * @value: value to search for
 * @index: out parameter where the index of the found element will be stored
 *
 * Return:
 *   0       if value is found
 *   -ERANGE if value is not found
 *   -EINVAL if parameters are invalid
 *
 * The array must be sorted according to the comparison function used in array_sort.
 */
int array_binary_search(const Array *array, int value, size_t *index);

#endif /* ARRAY_ALG_H */
