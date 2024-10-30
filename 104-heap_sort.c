#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 * swap - swaps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @first: address of first value
 * @second: address of second value
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
	}
	print_array((const int *)array, size);
}

/**
*sift_down - siftdown implementation
*
*@array: array to be sorted
*@start: start of array
*@end: end of array
*@size: size of array
*
*/
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t rt = start, _swp, child;

	while (leftchild(rt) <= end)
	{
		child = leftchild(root);
		_swp = rt;
		if (array[_swp] < array[child])
			_swp = child;
		if (child + 1 <= end &&
			array[_swp] < array[child + 1])
			_swp = child + 1;
		if (_swp == rt)
			return;
		swp(array, size, &array[rt], &array[_swp]);
		rt = _swp;
	}
}

/**
*heapify - makes heap in-place
*
*@array: array to be sorted
*@size: size of array
*
*/
void heapify(int *array, size_t size)
{
	ssize_t strt;

	strt = parent(size - 1);
	while (strt >= 0)
	{
		sift_down(array, strt, size - 1, size);
		strt--;
	}
}
/**
*heap_sort - sort an array by heap sort algorithm
*
*@array: array to sort
*@size: size of array
*
*/
void heap_sort(int *array, size_t size)
{
	size_t nd;

	if (!array || size < 2)
		return;
	heapify(array, size);
	nd = size - 1;
	while (nd > 0)
	{
		swap(array, size, &array[nd], &array[0]);
		nd--;
		sift_down(array, 0, nd, size);
	}
}
