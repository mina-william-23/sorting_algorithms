#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * merge_sorted_arrays - merges the two sorted portions of
 * the array a between the indexes l ... m and m + 1 ... r
 * @a: the array to sort
 * @l: start index
 * @m: middle index
 * @r: end index
 */

void merge_sorted_arrays(int a[], size_t l, size_t m, size_t r)
{
/*calculate the length of the left and right portions of the array*/
/*create temporary arrays to store these portions*/
/* used as index/counter variables for the 3 arrays a, temp_left, temp_right*/
	size_t left_length = m - l + 1;
	size_t right_length = r - m;
	int *copy_a = malloc(sizeof(int) * (r - l + 1));
	size_t i, j, k;
	printf("Merging...\n");
	/*copy the left portion into the temp_left array*/
	for (i = l, k = 0; i <= r; i++, k++)
		copy_a[k] = a[i];
	printf("[left]: ");
	print_array(copy_a, left_length);
	printf("[right]: ");
	print_array(copy_a + left_length, right_length);
	for (i = 0, j = left_length, k = l; k <= r; k++)
	{
		if ((i < left_length) &&
			(j >= right_length + left_length || copy_a[i] <= copy_a[j]))
		{
			a[k] = copy_a[i];
			i++;
		}
		else
		{
			a[k] = copy_a[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(a + l, left_length + right_length);
	free(copy_a);
}
/**
 * merge_sort_recursion - and the right index r.
 * This function implements the recursive
 * divide-and-conquer step of the merge sort algorithm, splitting the array
 * portion between l...r at the middle, and calling itself on each portion,
 * before applying the function to merge the sorted portions of the array
 * that will result.
 * Applies the merge sort algorithm to the array a between the left index l
 * @a: the array to sort
 * @l: start index
 * @r: end index
 */

void merge_sort_recursion(int a[], size_t l, size_t r)
{
	/*we stop recursion when l >= r*/
	if (r - l + 1 > 1)
	{
		/*find the midpoint of l and r */
		size_t m = l + (r - l + 1) / 2;
		/* apply the function recursively to the left and right portions split */
		/*at the midpoint*/
		merge_sort_recursion(a, l, m - 1);
		merge_sort_recursion(a, m, r);

		/*at this point both portions of the array have been sorted, and we now*/
		/* merge the sorted portions of the array*/

		merge_sorted_arrays(a, l, m - 1, r);
	}
}

/**
 * merge_sort - Performs a merge sort of the array a with the given length
 * ,the function
 * @array: tha array to sort
 * @size: length of array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_sort_recursion(array, 0, size - 1);
}
