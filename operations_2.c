/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:42:17 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/27 16:00:44 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <unistd.h>

// A yığınının tüm öğelerini bir pozisyon yukarı kaydırır (ra)
void ra(t_stack *a)
{
    if (a && a->next)
    {
        t_stack *first = a;
        t_stack *last = a;

        // Yığının sonuna kadar git
        while (last->next)
            last = last->next;

        // İlk öğeyi sona taşır
        a = first->next;
        first->next = NULL;
        last->next = first;
    }
	write(1, "ra\n", 3);
}

// B yığınının tüm öğelerini bir pozisyon yukarı kaydırır (rb)
void rb(t_stack *b)
{
    if (b && b->next)
    {
        t_stack *first = b;
        t_stack *last = b;

        // Yığının sonuna kadar git
        while (last->next)
            last = last->next;

        // İlk öğeyi sona taşır
        b = first->next;
        first->next = NULL;
        last->next = first;
    }
	write(1, "rb\n", 3);
}

// Hem A hem de B yığınlarını bir pozisyon yukarı kaydırır (rr)
void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
	write(1, "rr\n", 3);
}

// A yığınının tüm öğelerini bir pozisyon aşağı kaydırır (rra)
void rra(t_stack *a)
{
    if (a && a->next)
    {
        t_stack *last = a;
        t_stack *second_last = NULL;

        // Yığının sonuna kadar git
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }

        // Son öğeyi başa taşır
        second_last->next = NULL;
        last->next = a;
        a = last;
    }
	write(1, "rra\n", 4);
}

// B yığınının tüm öğelerini bir pozisyon aşağı kaydırır (rrb)
void rrb(t_stack *b)
{
    if (b && b->next)
    {
        t_stack *last = b;
        t_stack *second_last = NULL;

        // Yığının sonuna kadar git
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }

        // Son öğeyi başa taşır
        second_last->next = NULL;
        last->next = b;
        b = last;
    }
	write(1, "rrb\n", 4);
}