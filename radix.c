#include "push_swap.h"

static int get_max_bits(t_data *data)
{
	int *tmp_arr;
	int max;
	int max_bits;
	int i;

	i = 0;
	tmp_arr = data->arr;
	max = tmp_arr[0];
	max_bits = 0;

	while (i < data->size)
	{
		if (tmp_arr[i] > max)
			max = tmp_arr[i];
		i++;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void radix(t_data *data)
{
	int max_bits;
	int i;
	int j;

	max_bits = get_max_bits(data);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < data->size)
		{
			if ((data->arr[data->down] >> i) & 1)
				rotate(data, 'a');
			else
				push(data, 'b');
			j++;

		}
		while (stack_len(data, 'b') > 0)
		{
			push(data, 'a');
		}
		i++;
	}
}