/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:11:15 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/04 19:28:55 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(t_node *stack)
{
	t_node *tmp;
	int max;
	int max_bits;

	tmp = stack;
	max = tmp->value;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);	
}

void radix_sort(t_stack *stack)
{
	t_node *tmp;
	int i;
	int j;
	int max_bits;

	max_bits = get_max_bits(stack->a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < stack->a_size)
		{
			tmp = stack->a;
			if (((tmp->value >> i) & 1) == 1)
				ra(stack->a);
			else
				pb(stack);
		}
		while (stack->b_size)
			pa(stack);
		i++;
	}
}