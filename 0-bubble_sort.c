#include "sort.h"

/**
 * swap - this fuction is use to swap the element of the array
 * @a: first element to swap
 * @b: second element to swap
 * Return: void
 */
void array_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - a function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, lenght = size;
	bool sorted = false;

	if (array == NULL || size < 2)
		return;
	while (sorted == false)
	{
		sorted = true;
		for (j = 0; j < lenght - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				array_swap(array + j, array + j + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		lenght--;
	}
}
