/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:41:59 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/01 20:16:36 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

// Yığındaki üstteki iki öğeyi takas eder (sa)
void sa(t_node *a)
{
    if (a && a->next)
    {
        int temp = a->value;
        a->value = a->next->value;
        a->next->value = temp;
    }
	write(1, "sa\n", 3);
}

// Yığındaki üstteki iki öğeyi takas eder (sb)
void sb(t_node *b)
{
    if (b && b->next)
    {
        int temp = b->value;
        b->value = b->next->value;
        b->next->value = temp;
    }
	write(1, "sb\n", 3);
}

// Hem A hem de B yığınlarındaki üst öğeleri takas eder (ss)
void ss(t_node *a, t_node *b)
{
    sa(a);
    sb(b);
	write(1, "ss\n", 3);
}

#include <unistd.h>

// Yığından bir öğeyi A'ya taşır (pa)
void pa(t_stack *stack)
{
	if (stack->b)
	{
		t_node *temp = stack->b;
		stack->b = stack->b->next;
		temp->next = stack->a;
		stack->a = temp;
		stack->a_size++;
		stack->b_size--;
		write(1, "pa\n", 3);
	}
}

// Yığından bir öğeyi B'ye taşır (pb)
void pb(t_stack *stack)
{
	if (stack->a)
	{
		t_node *temp = stack->a;
		stack->a = stack->a->next;
		temp->next = stack->b;
		stack->b = temp;
		stack->a_size--;
		stack->b_size++;
		write(1, "pb\n", 3);
	}
}


// Hem A hem de B yığınlarını bir pozisyon aşağı kaydırır (rrr)
void rrr(t_node *a, t_node *b)
{
    rra(&a);
    rrb(&b);
	write(1, "rrr\n", 4);
}
