#include "push_swap.h"
#include <unistd.h>

void swap(t_data *data, char label)
{
	int tmp;

	if (data->up > 0 && label == 'b')
	{
		tmp = data->arr[data->up];
		data->arr[data->up] = data->arr[data->up - 1];
		data->arr[data->up - 1] = tmp;
		write(1, "sb\n", 3);
	}
	else if (data->down < data->size - 1 && label == 'a')
	{
		tmp = data->arr[data->down];
		data->arr[data->down] = data->arr[data->down + 1];
		data->arr[data->down + 1] = tmp;
		write(1, "sa\n", 3);
	}
}

void rotate(t_data *data, char label)
{
	int tmp;
	int i;

	i = 0;
	if (data->down < data->size - 1 && label == 'a')
	{
		tmp = data->arr[data->down];
		while (i < data->size - data->down - 1)
		{
			data->arr[data->down + i] = data->arr[data->down + i + 1];
			i++;
		}
		data->arr[data->down + i] = tmp;
		write(1, "ra\n", 3);
	}
	else if (data->up > 0 && label == 'b')
	{
		tmp = data->arr[data->up];
		while (data->up - i > 0)
		{
			data->arr[data->up - i] = data->arr[data->up - i - 1];
			i++;
		}
		data->arr[0] = tmp;
		write(1, "rb\n", 3);
	}
}

void reverse_rotate(t_data *data, char label)
{
	int tmp;
	int i;

	i = 0;
	if (data->down < data->size - 1 && label == 'a')
	{
		tmp = data->arr[data->size - 1];
		while (i < data->size - data->down - 1)
		{
			data->arr[data->size - i - 1] = data->arr[data->size - i - 2];
			i++;
		}
		data->arr[data->down] = tmp;
		write(1, "rra\n", 4);
	}
	else if (data->up > 0 && label == 'b')
	{
		tmp = data->arr[0];
		while (data->up - i > 0)
		{
			data->arr[i] = data->arr[i + 1];
			i++;
		}
		data->arr[data->up] = tmp;
		write(1, "rrb\n", 4);
	}
}
void push(t_data *data, char label)
{
	if (data->up + 1 > 0 && label == 'a')
	{
		data->up--;
		data->down--;
		write(1, "pa\n", 3);
	}
	else if (data->down < data->size && label == 'b')
	{
		data->up++;
		data->down++;
		write(1, "pb\n", 3);
	}
}