#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @size: Number of elements in an array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, temp;
	bool sorted = true;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);

			sorted = false;
		}
	}
	if (sorted == false)
	{
		bubble_sort(array, size);
	}
}



		
