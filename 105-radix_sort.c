#include "sort.h"
/**
 * getMax - function to get the maximum element in the array
 * @array: array to sort
 * @n: length of array
 * Return: the maximum element in the array
 */

int getMax(int *array, size_t n)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * radix_sort - LSD Radix Sort
 * @array: array to sort
 * @size: length of array
 */

void radix_sort(int *array, size_t size)
{
	size_t i;
	int max, exp;
	int *output;

	if (!array || size < 2)
		return;
	max = getMax(array, size);
	output = (int *)malloc(size * sizeof(int));
	exp = 1;
	if (output == NULL)
		return;
	while (max / exp > 0)
	{
		int count[10] = {0};
		/*Count the occurrences of each digit at the current place (exp)*/
		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;
		/*Calculate the cumulative count*/
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		/*Place the elements in the output based on their counts and current digit*/
		for (i = size - 1;; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
			if (i == 0)
				break;
		}
		/*Copy the sorted elements back to the original array*/
		for (i = 0; i < size; i++)
			array[i] = output[i];
		/*Print the array after sorting with current significant digit*/
		print_array(array, size);
		exp *= 10;
	}
	free(output);
}
