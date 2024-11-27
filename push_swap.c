/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:47:02 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/27 18:13:39 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Yığın içeriğini ekrana yazdırma fonksiyonu
void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

// Argümanları stack'e ekleme fonksiyonu
t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	for (i = 1; i < argc; i++)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->value = atoi(argv[i]);
		new_node->next = stack;
		stack = new_node;
	}
	return (stack);
}

// Stack'te eleman sayısı sayma
int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	get_last_value(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a || !a->next)
		return (1);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (!is_sorted(*a))
	{
		tmp = *a;
		while (tmp && tmp->next)
		{
			if (tmp->value > tmp->next->value
				&& tmp->value < get_last_value(*a))
				sa(*a);
			else if (tmp->value < tmp->next->value
				&& tmp->value > get_last_value(*a))
				rra(*a);
			else if (tmp->value < tmp->next->value
				&& tmp->value < get_last_value(*a))
				pb(*a, *b);
			else
				ra(*a);
			tmp = tmp->next;
		}
		while (!is_sorted(*b))
		{
			if ((*b)->value < get_last_value(*a))
				pa(*a, *b);
			else
				rb(*b);
		}
		if (is_sorted(*a))
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = create_stack(argc, argv);
	print_stack(a);
	sort_stack(&a, &b);
	print_stack(a);
	print_stack(b);
	return (0);
}
