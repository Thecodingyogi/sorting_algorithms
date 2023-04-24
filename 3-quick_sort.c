#include "sort.h"

/**
 * swap - Swaps two elements
 * @a: First element
 * @b: second element
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions an array using the last element as the pivot
 * @array: Array to be partitioned
 * @size: Number of elements in array
 * @start: starting index
 * @end: Ending index
 *
 * Return: The partition index
 */

int partition(int *array, size_t size, int start, int end)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * partition_sort - sorts an array of integers
 * @array: Array of integers to be sorted
 * @size: The length of the array
 * @start: start of index
 * @end: End of index
 */

void partition_sort(int *array, size_t size, int start, int end)
{
	if (start < end)
	{
		int pi = partition(array, size, start, end);

		partition_sort(array, size, start, pi - 1);
		partition_sort(array, size, pi + 1, end);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: number of elements in array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	partition_sort(array, size, 0, size - 1);
}
