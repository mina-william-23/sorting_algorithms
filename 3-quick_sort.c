#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort_lumuto - quick_sort_lumuto implementation
 * lumuto parition logic : use the last element as pivot
 * @array: array of integers
 * @start: start idx
 * @end: end idx
 * @sz: size of the array
 */
void quick_sort_lumuto(int *array, size_t start, size_t end, size_t sz)
{
	size_t i, left;
	int temp, pivot;

	/* if size less than or equal to 1 don't need sort */
	/* +1 to compute length because end, start is indexes */
	/* this also resolve the over flow as size_t if (left)end = 0 */
	/* and left -1 = will give overflow but +1 resolve that issue */
	/* if it was just signed int condition (end <= start) would be enough */
	if (end - start + 1 <= 1)
		return;

	pivot = array[end];
	left = start;
	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			if (left != i)
			{
				temp = array[left];
				array[left] = array[i];
				array[i] = temp;
				print_array(array, sz);
			}
			left++;
		}
	}
	/* left is right place for pivot so swap left with pivot(end) */
	if (array[left] != array[end])
	{
		array[end] = array[left];
		array[left] = pivot;
		print_array(array, sz);
	}

	quick_sort_lumuto(array, start, left - 1, sz);
	quick_sort_lumuto(array, left + 1, end, sz);
}

/**
 * quick_sort - quick sort implementation
 * @array: array of integers
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	quick_sort_lumuto(array, 0, size - 1, size);
}
