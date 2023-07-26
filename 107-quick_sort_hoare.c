#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort_recursion - quick_sort_hoare implementation
 * hoare parition logic : use the first element as pivot and two pointers
 * @array: array of integers
 * @start: start idx
 * @end: end idx
 * @sz: used to print
 */
void quick_sort_recursion(int *array, size_t start, size_t end, size_t sz)
{
	size_t i, j;
	int temp, pivot;

	if (end - start + 1 <= 1)
		return;

	pivot = array[end];
	i = start - 1;
	j = end + 1;

	while (j - i + 1 > 1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j + 1 == 0 || j <= i)
			break;
		if (array[i] > array[j])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, sz);
		}
	}
	quick_sort_recursion(array, start, i - 1, sz);
	quick_sort_recursion(array, i, end, sz);
}

/**
 * quick_sort_hoare - quick sort implementation
 * @array: array of integers
 * @size: size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
