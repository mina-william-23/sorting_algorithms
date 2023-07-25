#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - count sort algorithm
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int *cnt_arr, mx;
	size_t idx, cnt_idx;
	char *delim = "";

	if (!array || size < 2)
		return;

	mx = array[0];
	for (idx = 1; idx < size; idx++)
	{
		if (array[idx] > mx)
			mx = array[idx];
	}
	cnt_arr = malloc(sizeof(int) * mx + 1);
	if (!cnt_arr)
		return;
	for (cnt_idx = 0; cnt_idx <= (size_t)mx; cnt_idx++)
		cnt_arr[cnt_idx] = 0;
	for (idx = 0; idx < size; idx++)
		cnt_arr[array[idx]]++;
	for (cnt_idx = 0, idx = 0; cnt_idx <= (size_t)mx; cnt_idx++)
	{
		if (cnt_arr[cnt_idx])
		{
			/* replace the old array with new data sorted */
			while (cnt_arr[cnt_idx]--)
			{
				array[idx++] = cnt_idx;
				printf("%s%lu", delim, idx);
			}
		}
		else
		{
			printf("%s%lu", delim, idx);
		}
		delim = ", ";
	}
	printf("\n");
}
