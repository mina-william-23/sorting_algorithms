# Sorting Algorithms

![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRztBz3thnxU2MZwqucC6GD-YnuzDLpXk9weg&usqp=CAU)
![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQE2x8GeiLD2O8kQMi_nu59o69xACZT2MhPuw&usqp=CAU)

### General

- At least four different sorting algorithms
- What is the Big O notation, and how to evaluate the time complexity of an algorithm
- How to select the best sorting algorithm for a given input
- What is a stable sorting algorithm

## Helper Files

- [print_array.c](./print_array.c): C function that prints an array of integers.
- [print_list.c](./print_list.c): C function that prints a `listint_t` doubly-linked list.

## Header Files

- [sort.h](./sort.h): Header file containing definitions and prototypes for all types and functions written for the project.

Data Structure:

```
typedef struct listint_s
{
 const int n;
 struct listint_s *prev;
 struct listint_s *next;
} listint_t;
```

Function Prototypes:

| File                       | Prototype                                         |
| -------------------------- | ------------------------------------------------- |
| `print_array.c`            | `void print_array(const int *array, size_t size)` |
| `print_list.c`             | `void print_list(const listint_t *list)`          |
| `0-bubble_sort.c`          | `void bubble_sort(int *array, size_t size);`      |
| `1-insertion_sort_list.c`  | `void insertion_sort_list(listint_t **list);`     |
| `2-selection-sort.c`       | `void selection_sort(int *array, size_t size);`   |
| `3-quick_sort.c`           | `void quick_sort(int *array, size_t size);`       |
| `102-counting_sort.c`      | `void counting_sort(int *array, size_t size);`    |
| `103-merge_sort.c`         | `void merge_sort(int *array, size_t size);`       |
| `104-heap_sort.c`          | `void heap_sort(int *array, size_t size);`        |
| `105-radix_sort.c`         | `void radix_sort(int *array, size_t size);`       |
| `107-quick_sort_hoare.c`   | `void quick_sort_hoare(int *array, size_t size);` |

## Tasks

- **0. Bubble sort**
  - [0-bubble_sort.c](./0-bubble_sort.c): C function that sorts an array of integers in ascending order using the Bubble Sort algorithm.
  - Prints the array after each swap.
  - [0-O](./0-O): Text file containing the best, average, and worst case time complexities of the Bubble Sort algorithm, one per line.

- **1. Insertion sort**
  - [1-insertion_sort_list.c](./1-insertion_sort_list.c): C function that sorts a `listint_t` doubly-linked list of integers in ascending order using the
  Insertion Sort algorithm.
  - Prints the list after each swap.
  - [1-O](./1-O): Text file containing the best, average, and worst case time complexities of the Insertion Sort algorithm, one per line.

- **2. Selection sort**
  - [2-selection_sort.c](./2-selection_sort.c): C function that sorts an array of integers in ascending order using the Selection Sort algorithm.
  - Prints the array after each swap.
  - [2-O](./2-O): Text file containing the best, average, and worst case time complexities of the Selection Sort algorithm, one per line.

- **3. Quick sort**
  - [3-quick_sort.c](./3-quick_sort.c): C function that sorts an array of integers in ascending order using the Quick Sort algorithm.
  - Implements the Lomuto partition scheme.
  - Always uses the last element of the partition being sorted as the pivot.
  - Prints the array after each swap.
  - [3-O](./3-O): Text file containing the best, average, and worst case time complexities of the Quick Sort Lomuto Partition scheme algorithm, one per line.

- **6. Counting sort**
  - [102-counting_sort.c](./102-counting_sort.c): C function that sorts an array of integers in ascending order using the Counting Sort algorithm.
  - Assumes that the array will only contain numbers `>= 0`.
  - Prints the counting array after it has been initialized.
  - [102-O](./102-O): Text file containing the best, average, and worst case time complexities of the Counting Sort algorithm, one per line.

- **7. Merge sort**
  - [103-merge_sort.c](./103-merge_sort.c): C function that sorts an array of integers in ascending order using the Merge Sort algorithm.
  - Implements the `top-down` Merge Sort algorithm.
    - When an array is divided, the size of the left subarray is always less than or equal to the size of the right subarray.
    - Always sorts the left subarray before the right one.
  - Prints subarrays each time they are merged.
  - [103-O](./103-O): Text file containing the best, average, and worst case time complexities of the Merge Sort algorithm, one per line.

- **8. Heap sort**
  - [104-heap_sort.c](./104-heap_sort.c): C function that sorts an array of integers in ascending order using the Heap Sort algorithm.
  - Implements the `sift-down` Heap Sort algorithm.
  - Prints the array after each swap.
  - [104-O](./104-O): Text file containing the best, average, and worst case time complexiites of the Heap Sort algorithm, one per line.

- **9. Radix sort**
  - [105-radix_sort.c](./105-radix_sort.c): C function that sorts an array of integers in ascending order using the Radix Sort algorithm.
  - Implements the Least-Significant-Digit (LSD) Radix Sort algorithm.
  - Assumes that the array will only contain numbers `>= 0`.
  - Prints the array for each significant digit increase.
  - [105-O](./105-O): Text file containing the best, average, and worst case time complexities of the Radix Sort algorithm, one per line.

- **11. Quick Sort - Hoare Partition scheme**
  - [107-quick_sort_hoare.c](./107-quick_sort_hoare.c): C function that sorts an array of integers in ascending order using the Quick Sort algorithm.
  - Implements the Hoare partition scheme.
  - Always uses the last elemement of the partition being sorted as the pivot.
  - Prints the array after each swap.
  - [107-O](./107-O): Text file containing the best, average, and worst case time complexities of the Quick Sort Hoare Partition cheme algorithm, one per line.
