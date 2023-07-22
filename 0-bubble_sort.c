#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - bubble sort implementation
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, nw_sz_to_sort, sz = size;
	int temp;

	while (sz > 1)
	{

		nw_sz_to_sort = 0;
		for (j = 1; j < sz; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				nw_sz_to_sort = j;
			}
		}
		sz = nw_sz_to_sort;
	}
}
