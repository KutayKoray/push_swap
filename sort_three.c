/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:33:27 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/21 13:44:54 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	sort_three(t_data *data)
{
	if (data->arr[data->down] > data->arr[data->down + 1]
		&& data->arr[data->down] < data->arr[data->down + 2])
		swap(data, 'a');
	else if (data->arr[data->down] > data->arr[data->down + 1]
		&& data->arr[data->down] > data->arr[data->down + 2]
		&& data->arr[data->down + 1] < data->arr[data->down + 2])
		rotate(data, 'a');
	else if (data->arr[data->down] > data->arr[data->down + 1]
		&& data->arr[data->down] > data->arr[data->down + 2]
		&& data->arr[data->down + 1] > data->arr[data->down + 2])
	{
		rotate(data, 'a');
		swap(data, 'a');
	}
	else if (data->arr[data->down] < data->arr[data->down + 1]
		&& data->arr[data->down] > data->arr[data->down + 2])
		reverse_rotate(data, 'a');
	else if (data->arr[data->down] < data->arr[data->down + 1]
		&& data->arr[data->down] < data->arr[data->down + 2]
		&& data->arr[data->down + 1] > data->arr[data->down + 2])
	{
		reverse_rotate(data, 'a');
		swap(data, 'a');
	}
}

static void	find_min_and_index(t_data *data, int *min_index)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < data->size - data->down)
	{
		if (data->arr[i + data->down] < min)
		{
			min = data->arr[i + data->down];
			*min_index = i;
		}
		i++;
	}
}

static void	move_min_to_b(t_data *data, int min_index, int size)
{
	if (min_index == 1)
		swap(data, 'a');
	else if (min_index == 2)
	{
		rotate(data, 'a');
		swap(data, 'a');
	}
	else if (min_index == 3 && size == 4)
		reverse_rotate(data, 'a');
	else if (min_index == 3 && size == 5)
	{
		reverse_rotate(data, 'a');
		reverse_rotate(data, 'a');
	}
	else if (min_index == 4)
		reverse_rotate(data, 'a');
	if (!is_sorted(data, 'a'))
		push(data, 'b');
}

void	sort_four_and_five(t_data *data, int size)
{
	int	min_index;

	if (size == 4)
	{
		find_min_and_index(data, &min_index);
		move_min_to_b(data, min_index, 4);
		sort_three(data);
		while (stack_len(data, 'b') != 0)
			push(data, 'a');
	}
	if (size == 5)
	{
		find_min_and_index(data, &min_index);
		move_min_to_b(data, min_index, 5);
		find_min_and_index(data, &min_index);
		move_min_to_b(data, min_index, 4);
		sort_three(data);
		while (stack_len(data, 'b') != 0)
			push(data, 'a');
	}
}
