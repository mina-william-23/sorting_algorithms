#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* get_max - get max int from array
* @array: arary
* @size: array size
* Return: max int in array
*/
int get_max(int *array, size_t size)
{
	int mx;
	size_t idx;

	mx = array[0];
	for (idx = 1; idx < size; idx++)
	{
		if (array[idx] > mx)
			mx = array[idx];
	}
	return (mx);
}

/**
 * counting_sort - count sort algorithm
 * @a: array
 * @size: size
 */
void counting_sort(int *a, size_t size)
{
	int *b, *cnt_arr, mx;
	size_t idx, cnt_idx;

	if (!a || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (!b)
		return;
	for (idx = 0; idx < size; idx++)
		b[idx] = a[idx];

	mx = get_max(a, size);

	cnt_arr = malloc(sizeof(int) * (mx + 1));
	if (!cnt_arr)
	{
		free(b);
		return;
	}
	for (cnt_idx = 0; cnt_idx <= (size_t) mx; cnt_idx++)
		cnt_arr[cnt_idx] = 0;

	for (idx = 0; idx < size; idx++)
		cnt_arr[a[idx]]++;

	for (cnt_idx = 1; cnt_idx <= (size_t) mx; cnt_idx++)
		cnt_arr[cnt_idx] += cnt_arr[cnt_idx - 1];
	print_array(cnt_arr, mx + 1);

	for (idx = size - 1; ; idx--)
	{
		b[--cnt_arr[a[idx]]] = a[idx];
		if (idx == 0)
			break;
	}
	for (idx = 0; idx < size; idx++)
		a[idx] = b[idx];

	free(cnt_arr);
}
