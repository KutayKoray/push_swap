/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:41:59 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/27 15:59:49 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

// Yığındaki üstteki iki öğeyi takas eder (sa)
void sa(t_stack *a)
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
void sb(t_stack *b)
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
void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
	write(1, "ss\n", 3);
}

// Yığından bir öğe A'ya taşır (pa)
void pa(t_stack *a, t_stack *b)
{
    if (b)
    {
        t_stack *temp = b;
        b = b->next;
        temp->next = a;
        a = temp;
    }
	write(1, "pa\n", 3);
}

// Yığından bir öğe B'ye taşır (pb)
void pb(t_stack *a, t_stack *b)
{
    if (a)
    {
        t_stack *temp = a;
        a = a->next;
        temp->next = b;
        b = temp;
    }
	write(1, "pb\n", 3);
}

// Hem A hem de B yığınlarını bir pozisyon aşağı kaydırır (rrr)
void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
	write(1, "rrr\n", 4);
}
