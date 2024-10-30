#include "sort.h"

/**
 * bubble_sort - sorts array of integers
 *
 * @array: array of integers
 * @size: size of aray
 *
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t u, l;

	if (!array || !size)
		return;
	u = 0;
	while (u < size)
	{
		for (l = 0; l < size - 1; l++)
		{
			if (array[l] > array[l + 1])
			{
				tmp = array[l];
				array[l] = array[l + 1];
				array[l + 1] = tmp;
				print_array(array, size);
			}
		}
		u++;
	}
}
