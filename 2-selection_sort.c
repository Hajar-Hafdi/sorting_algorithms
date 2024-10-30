#include "sort.h"

/**
 * selection_sort - sorts using selection
 *
 * @array: array to sort
 * @size: size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t m, j, k;
	int tmp;

	if (!array || size < 2)
		return;
	for (j = 0; j < size - 1; j++)
	{
		m = j;
		for (k = j + 1; k < size; k++)
		{
			if (array[k] < array[m])
				m = k;
		}
		if (m != j)
		{
			tmp = array[j];
			array[j] = array[m];
			array[m] = tmp;
			print_array(array, size);
		}
	}
}
