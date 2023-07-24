#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge_sort_recursion(int a[], size_t l, size_t r);
void merge_sorted_arrays(int a[], size_t l, size_t m, size_t r);

/**
 * merge_sort - Performs a merge sort of the array a with the given length
 * ,the function
 * @array: tha array to sort
 * @size: length of array
 */
void merge_sort(int *array, size_t size)
{

merge_sort_recursion(array, 0, size - 1);
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
if (l < r)
{
/*find the midpoint of l and r */
size_t m = l + (r - l) / 2;
/* apply the function recursively to the left and right portions split */
/*at the midpoint*/
merge_sort_recursion(a, l, m);
merge_sort_recursion(a, m + 1, r);

/*at this point both portions of the array have been sorted, and we now*/
/* merge the sorted portions of the array*/


merge_sorted_arrays(a, l, m, r);
}
}
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
int *temp_left = malloc(sizeof(int) * left_length);
int *temp_right = malloc(sizeof(int) * right_length);
size_t i, j, k;

printf("Merging...\n");
/*copy the left portion into the temp_left array*/
for (i = 0; i < left_length; i++)
temp_left[i] = a[l + i];
printf("[left]: ");
print_array(temp_left, left_length);
/*copy the right portion into the temp_right array*/
for (i = 0; i < right_length; i++)
temp_right[i] = a[m + 1 + i];
printf("[right]: ");
print_array(temp_right, right_length);

/*
 * Use i to move through the indexes of temp_left, j to move through the
 * indexes of temp_right, and k to move through the portion of the array
 * a from l ... r.  We basically keep checking the "head" of temp_left
 * and temp_right (knowing both arrays are sorted) and put the smaller of
 * the two into array a (using i, j, k to move through the arrays).  When
 * we run out elements in either temp_left or temp_right, the remaining
 * elements from the other array will be copied over into a.
 */

for (i = 0, j = 0, k = l; k <= r; k++)
{
if ((i < left_length) &&
	(j >= right_length || temp_left[i] <= temp_right[j]))
{
	a[k] = temp_left[i];
	i++;
}
else
{
	a[k] = temp_right[j];
	j++;
}
}
printf("[Done]: ");
print_array(a + l, left_length + right_length);
free(temp_left);
free(temp_right);
}
