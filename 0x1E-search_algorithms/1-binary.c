#include "search_algos.h"

/**
 * binary_search_recursive - Recursively searches for a value in a sorted
 * array of integers using the Binary search algorithm.
 * @array: A pointer to the first element of the array to search in
 * @left: The starting index of the subarray to search in
 * @right: The ending index of the subarray to search in
 * @value: The value to search for
 *
 * Return: The index where value is located or -1 if it is not present
 */
int binary_search_recursive(int *array, int left, int right, int value)
{
	int mid;
	int i;

	if (left <= right)
	{
		mid = left + (right - left) / 2;

		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d\n", array[i]);
		printf("%d\n", array[right]);

		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			return (binary_search_recursive(array, mid + 1, right, value));
		if (array[mid] > value)
			return (binary_search_recursive(array, left, mid - 1, value));
	}
	return (-1);
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
	if (array == NULL)
		return (-1);
	return (binary_search_recursive(array, 0, size - 1, value));
}
