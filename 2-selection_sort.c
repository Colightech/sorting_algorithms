#include "sort.h"

/**
 * swap - this function is use to swap two element in an array
 * @a: element A
 * @b: element B
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
 * selection_sort - this fuction implement Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *least;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		least = array + i;
		for (j = i + 1; j < size; j++)
		{
			least = (array[j] < *least) ? (array + j) : least;
		}
		if (array + i != least)
		{
			swap(array + i, least);
			print_array(array, size);
		}
	}
}
