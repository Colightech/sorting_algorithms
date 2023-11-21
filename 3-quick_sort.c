#include "sort.h"

/**
 * swap - this fuction is use to swap the element of the array
 * @a: first element to swap
 * @b: second element to swap
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - this function is use to partition
 * the array
 * @array: array to partition
 * @size: size of array
 * @low: lower bound index of the array
 * @high: higher bound index of the array
 * Return: return the pivot index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot = array + high;
	int start, end = low;

	for (start = low; start < high; start++)
	{
		if (array[start] < *pivot)
		{
			if (end < start)
			{
				swap(array + start, array + end);
				print_array(array, size);
			}
			end++;
		}
	}
	if (array[end] > *pivot)
	{
		swap(array + end, pivot);
		print_array(array, size);
	}
	return (end);
}

/**
 * lomuto_sort_recursion - this function is use to recursively
 * for sub partitioning
 * @array: the to be sorted
 * @size: size of array
 * @low: lower bound of bthe array
 * @high: higher bound of the array
 * Return: void
 */
void lomuto_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (high - low > 0)
	{
		pivot_index = lomuto_partition(array, size, low, high);
		lomuto_sort_recursion(array, size, low, pivot_index - 1);
		lomuto_sort_recursion(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - a function that sorts an array of
 *  integers in ascending order using the Quick sort algorithm
 *  @array: the array to be sorted
 *  @size: size of array
 *  Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort_recursion(array, size, 0, size - 1);
}
