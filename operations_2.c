/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:42:17 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/04 15:46:29 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <unistd.h>

void ra(t_node *a) {
    if (a && (a)->next) 
	{
        t_node *first = a;
        t_node *last = a;

        while (last->next)
            last = last->next;

        a = first->next;
        first->next = NULL;
        last->next = first;
		write(1, "ra\n", 3);
    }
}

void rb(t_node **b) {
    if (*b && (*b)->next) {
        t_node *first = *b;
        t_node *last = *b;

        // Yığının sonuna kadar git
        while (last->next)
            last = last->next;

        // İlk düğümü sona taşı
        *b = first->next;  // Orijinal 'b' güncellenir
        first->next = NULL;
        last->next = first;
    }
    write(1, "rb\n", 3);
}


// Hem A hem de B yığınlarını bir pozisyon yukarı kaydırır (rr)
void rr(t_node *a, t_node *b)
{
    ra(a);
    rb(&b);
	write(1, "rr\n", 3);
}

// A yığınının tüm öğelerini bir pozisyon aşağı kaydırır (rra)
void rra(t_node **a)
{
    if (*a && (*a)->next)
    {
        t_node *last = *a;
        t_node *second_last = NULL;

        // Yığının sonuna kadar git
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }

        // Son öğeyi başa taşır
        second_last->next = NULL;
        last->next = *a;
        *a = last; // Orijinal 'a' güncellenir
    }
    write(1, "rra\n", 4);
}

// B yığınının tüm öğelerini bir pozisyon aşağı kaydırır (rrb)
void rrb(t_node **b)
{
    if (*b && (*b)->next)
    {
        t_node *last = *b;
        t_node *second_last = NULL;

        // Yığının sonuna kadar git
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }

        // Son öğeyi başa taşır
        second_last->next = NULL;
        last->next = *b;
        *b = last; // Orijinal 'b' güncellenir
    }
    write(1, "rrb\n", 4);
}
