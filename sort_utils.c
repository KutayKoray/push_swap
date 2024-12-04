/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:59:00 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/01 20:10:59 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value)
		sa(stack->a);
	if (stack->a->next->value > stack->a->next->next->value)
		rra(&stack->a);
	if (stack->a->value > stack->a->next->value)
		sa(stack->a);
}

void bubble_sort(t_node *node)
{
	int tmp_val;
	t_node *tmp;

	tmp = node;
	while  (node->next)
	{
		if (node->value > node->next->value)
		{
			tmp_val = node->value;
			node->value = node->next->value;
			node->next->value = tmp_val;
			node = tmp;
			}
		else
			node = node->next;
	}
}

int get_median(t_node *node, int size)
{
	int i;
	if (!node->value)
		return (0);
	while (i < size / 2)
	{
		i++;
		node = node->next;
	}
	return (node->value);
}
