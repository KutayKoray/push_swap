#include "push_swap.h"
#include <stdlib.h>

int	stack_len(t_data *data, char label)
{
	int	i;

	i = 0;
	if (label == 'a')
		i = data->size - data->down;
	else
		i = data->up + 1;
	return (i);
}

int	is_sorted(t_data *data, char label)
{
	int	i;

	i = 0;
	if (label == 'a' && stack_len(data, 'a') > 1)
	{
		while (i < data->size - data->down - 1)
		{
			if (data->arr[data->down + i] > data->arr[data->down + i + 1])
				return (0);
			i++;
		}
	}
	else if (label == 'b' && stack_len(data, 'b') > 1)
	{
		while (i < data->up)
		{
			if (data->arr[data->up - i] < data->arr[data->up - i - 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	is_full_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size - 1)
	{
		if (data->arr[i] > data->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	tmp_val;
	int	*tmp_arr;

	i = 0;
	tmp_arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		tmp_arr[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < (size - 1))
	{
		if (tmp_arr[i] > tmp_arr[i + 1])
		{
			tmp_val = tmp_arr[i];
			tmp_arr[i] = tmp_arr[i + 1];
			tmp_arr[i + 1] = tmp_val;
			i = 0;
		}
		else
			i++;
	}
	return (tmp_arr);
}

int	*replace(int *arr, int *arr_sorted, int size)
{
	int	*new_arr;
	int	i;
	int	n;
	int	j;

	n = 0;
	i = 0;
	new_arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == arr_sorted[j])
			{
				new_arr[n] = j;
				n++;
			}
			j++;
		}
		i++;
	}
	return (new_arr);
}
