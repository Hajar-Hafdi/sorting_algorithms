#include "sort.h"

/**
 * swap - swaps two integer values
 *
 * @array: int array to be sorted
 * @size: size of the array
 * @first: add of first val
 * @second: add of 2nd val
 *
 * Return: void
 */
void swap(int *array, size_t size, int *first, int *second)
{
	if (*first != *second)
	{
		*first = *first + *second;
		*second = *first - *second;
		*first = *first - *second;
		print_array((const int *)array, size);
	}
}
/**
 * lum_parti - partitions the array
 *
 * @array: int array ty to be sorted
 * @size: size of array
 * @lom: the low index
 * @high: high index
 *
 * Return: size_t
 */
size_t lum_parti(int *array, size_t size, ssize_t lom, ssize_t high)
{
	int l, n, pvt = array[high];

	for (l = n = lom; n < high; n++)
		if (array[n] < pvt)
			swap(array, size, &array[n], &array[l++]);
	swap(array, size, &array[l], &array[high]);
	return (l);
}
/**
 * quick_s - quicksorts via Lomuto part scheme
 *
 * @array: the integer array to sort
 * @size: the size of the array
 * @lom: the low index of the sort range
 * @high: high index of the sort range
 *
 * Return: void
 */
void quick_s(int *array, size_t size, ssize_t lom, ssize_t high)
{
	if (lom < high)
	{
		size_t pv = lum_parti(array, size, lom, high);

		quick_s(array, size, lom, pv - 1);
		quick_s(array, size, pv + 1, high);
	}
}
/**
 * quick_sort - quicksorts
 *
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_so(array, size, 0, size - 1);
}
