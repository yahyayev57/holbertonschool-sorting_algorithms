#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: pointer to first int
 * @b: pointer to second int
 */
void swap(int *a, int *b)
{
	int temp;

	if (a == b)
		return;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: the array to partition
 * @low: start index
 * @high: end index (pivot)
 * @size: size of the array (for print_array)
 *
 * Return: the partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive quick sort implementation
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
