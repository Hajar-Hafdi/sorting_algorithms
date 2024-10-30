#include "sort.h"

/**
 * merge_compare - compares merges
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_compare(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, midle;

	j = midle = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, midle - start);
	printf("[right]: ");
	print_array(array + midle, stop - midle);
	for (k = start; k < stop; k++)
		if (i < midle && (j >= stop || array[i] <= array[j]))
		{
			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_sort_top_down - sorts top to down recursively
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t middle;

	middle = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_sort_top_down(new, start, middle, array);
	merge_sort_top_down(new, middle, stop, array);
	merge_compare(array, start, stop, new);
}


/**
 * merge_sort - sorts an array by merge sort algorithm
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *new_a;
	size_t u;


	if (!array || size < 2)
		return;

	new_a = malloc(sizeof(int) * size);
	if (!new_a)
		return;
	for (u = 0; u < size; u++)
		new_a[u] = array[u];
	merge_sort_top_down(new_a, 0, size, array);
	free(new_a);
}
