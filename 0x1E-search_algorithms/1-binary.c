#include "search_algos.h"

/**
 * binary_search_recursive - Recursively searches for a value in a sorted
 * array of integers using the Binary search algorithm.
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int binary_search_recursive(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (binary_search_recursive(array, half, value));

	half++;

	return (binary_search_recursive(array + half, size - half, value) + half);
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The index where value is located or -1 if it is not present
 */
int binary_search(int *array, size_t size, int value) 
{
	int index;

	index = binary_search_recursive(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
