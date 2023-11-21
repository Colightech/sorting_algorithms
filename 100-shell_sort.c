#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: the array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, h = 1;

	if (array == NULL || size < 2)
		return;

	while (h < (size / 3))
	{
		h = 3 * h + 1;
	}

	for (; h >= 1; h /= 3)
	{
		for (i = h; i < size; i++)
		{
			j = i;
			while (j >= h && array[j - h] > array[j])
			{
				temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
				j = j - h;
			}
		}
		print_array(array, size);
	}
}
