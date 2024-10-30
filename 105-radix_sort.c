#include "sort.h"

/**
 * get_digit - gets a digit from a number
 * @number: the integer
 * @digit: the digit position to get
 *
 * Return: the digit value at given position
**/
int get_digit(long number, int digit)
{
	long l = 0L, pow = 1L, result;

	for (l = 0; l < digit; l++)
		pow *= 10L;
	result = ((number / pow) % 10);
	return (result);
}

/**
 * radix_pass - sorts by radix
 * @array: the integer array to sort
 * @size: the size of the array
 * @digit: the current digit to check
 * @new_array: target array of same size
 *
 * Return: void.
 */
int radix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t u;
	int buckts[10] = {0};

	for (u = 0; u < size; u++)
		buckts[get_digit(array[u], digit)]++;
	for (u = 1; u <= 9; u++)
		buckts[u] += buckts[u - 1];
	for (u = size - 1; u > -1; u--)
		new_array[buckts[get_digit(array[u], digit)]-- - 1] = array[u];
	return (1);
}

/**
 * radix_sort - sorts an array by radix algorithm
 * @size: the size of the array
 * @array: the integer array to sort
 *
 * Return: the gap size
 */
void radix_sort(int *array, size_t size)
{
	int *old, *new, *tmp_ptr, *ptr, max = 0;
	size_t u, sd = 1;

	if (!array || size < 2)
		return;

	for (u = 0; u < size; u++)
		if (array[u] > max)
			max = array[u];
	while (max /= 10)
		sd++;
	old = array;
	new = ptr = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (u = 0; u < sd; u++)
	{
		radix_pass(old, (ssize_t)size, u, new);
		tmp_ptr = old;
		old = new;
		new = tmp_ptr;
		print_array(old, size);
	}
	for (u = 0; u < size; u++)
		array[u] = old[u];
	free(ptr);
}
