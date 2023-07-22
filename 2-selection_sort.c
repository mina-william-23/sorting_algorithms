#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - selection sort implementation
 * @array: array of integers
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, mn_idx;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		mn_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[mn_idx])
				mn_idx = j;
		}
		if (mn_idx != i)
		{
			temp = array[i];
			array[i] = array[mn_idx];
			array[mn_idx] = temp;
			/* print array if only changed */
			print_array(array, size);
		}
	}
}
