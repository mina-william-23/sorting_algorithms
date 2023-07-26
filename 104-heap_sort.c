#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - swap two int pointers
 * @num1: int pointer1
 * @num2: int pionter2
 */
void swap_ints(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * heapify - down word heap buill logic
 * @array: array to build heap in
 * @size: size to check in current heap
 * @idx: start index
 * @print_size: full size of array
 */
void heapify(int *array, size_t size, size_t idx, size_t print_size)
{
	size_t mx_idx, parent_idx, child1_idx, child2_idx;

	/* logic works on indexes start from 1 so we add 1 */
	/* in process of computing the first child idx */
	/* as parent = i child1 = i*2 child2 = child1 + 1 */
	/* this is ascending array[child1_idx] > array[parent_idx]i */
	/* array[child2_idx] > array[mx_idx] */
	/* this is descending array[child1_idx] < array[parent_idx] */
	/*array[child2_idx] < array[mx_idx] */
	mx_idx = idx;
	parent_idx = idx;
	child1_idx = parent_idx * 2 + 1;
	child2_idx = child1_idx + 1;
	if (child1_idx < size && array[child1_idx] > array[parent_idx])
		mx_idx = child1_idx;
	if (child2_idx < size && array[child2_idx] > array[mx_idx])
		mx_idx = child2_idx;
	if (array[mx_idx] != array[parent_idx])
	{
		swap_ints(array + parent_idx, array + mx_idx);
		print_array(array, print_size);
		heapify(array, size, mx_idx, print_size);
	}
}

/**
 * heap_sort - heap sort algorithm
 * @array: not sorted array;
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t idx;

	if (!array || size < 2)
		return;

	/* build heap (nlog(n))*/
	for (idx = size / 2 - 1; ; idx--)
	{
		heapify(array, size, idx, size);
		if (idx == 0)
			break;
	}
	/* sort heap (nlog(n))*/
	/* print_size_flag = size;*/
	for (idx = size - 1; ; idx--)
	{
		if (array[0] != array[idx])
		{
			swap_ints(array, array + idx);
			print_array(array, size);
			heapify(array, idx, 0, size);
		}
		if (idx == 0)
			break;
	}
}
