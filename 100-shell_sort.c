#include "sort.h"

/**
 * get_max_gap - gets the a maximum Knuth Sequence gap for this size
 * @size: size of the array
 *
 * Return: the gap size
 */
size_t get_max_gap(size_t size)
{
	size_t gg = 1;

	while (gg < size)
		gg = gg * 3 + 1;
	return ((gg - 1) / 3);
}

/**
 * shell_sort - Sorts an array of integers
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t u, j, gp;

	if (!array || size < 2)
		return;

	for (gp = get_max_gap(size); gp; gp = (gp - 1) / 3)
	{
		for (u = gp; u < size; u++)
		{
			tmp = array[u];
			for (j = u; j > gp - 1 && array[j - gp] > tmp; j -= gp)
				array[j] = array[j - gp];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
