#include "push_swap.h"
#include <limits.h>

void sort_three(t_data *data)
{
	if (data->arr[data->down] > data->arr[data->down + 1] && data->arr[data->down] < data->arr[data->down + 2])
		swap(data, 'a');
	else if (data->arr[data->down] > data->arr[data->down + 1] && data->arr[data->down] > data->arr[data->down + 2] && data->arr[data->down + 1] < data->arr[data->down + 2])
	{
		swap(data, 'a');
		reverse_rotate(data, 'a');
	}
	else if (data->arr[data->down] > data->arr[data->down + 1] && data->arr[data->down] > data->arr[data->down + 2] && data->arr[data->down + 1] > data->arr[data->down + 2])
		rotate(data, 'a');
	else if (data->arr[data->down] < data->arr[data->down + 1] && data->arr[data->down] > data->arr[data->down + 2])
		reverse_rotate(data, 'a');
	else if (data->arr[data->down] < data->arr[data->down + 1] && data->arr[data->down] < data->arr[data->down + 2] && data->arr[data->down + 1] > data->arr[data->down + 2])
		swap(data, 'a');
}
void find_min_and_index(t_data *data, int *min, int *min_index)
{
    int i;

    i = 0;
    *min = INT_MAX;
    while (i < data->size - data->down)
    {
        if (data->arr[data->down + i] < *min)
        {
            *min = data->arr[data->down + i];
            *min_index = i;
        }
        i++;
    }
}

void move_min_to_b(t_data *data, int min_index)
{
    if (min_index == 0)
        push(data, 'b');
    else if (min_index == 1)
    {
        reverse_rotate(data, 'a');
        push(data, 'b');
    }
    else if (min_index == 2)
    {
        rotate(data, 'a');
        push(data, 'b');
    }
}

void sort_four(t_data *data)
{
    int min;
    int min_index;

    find_min_and_index(data, &min, &min_index);
    move_min_to_b(data, min_index);
    sort_three(data);
    push(data, 'a');
}
