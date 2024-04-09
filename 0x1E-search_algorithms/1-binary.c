#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search_recursive - Recursively searches for a value in a sorted
 * array of integers using the Binary search algorithm.
 * @array: input array
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 * @value: value to search for
 * Return: index of the number
 */
int binary_search_recursive(int *array, size_t start, size_t end, int value)
{
    if (array == NULL || start > end)
        return (-1);

    size_t mid = start + (end - start) / 2;

    printf("Searching in array");
    for (size_t i = start; i <= end; i++)
        printf("%s %d", (i == start) ? ":" : ",", array[i]);
    printf("\n");

    if (array[mid] == value)
        return (mid);

    if (array[mid] > value)
        return (binary_search_recursive(array, start, mid - 1, value));
    else
        return (binary_search_recursive(array, mid + 1, end, value));
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The index where value is located or -1 if it is not present
 */
int binary_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return binary_search_recursive(array, 0, size - 1, value);
}
