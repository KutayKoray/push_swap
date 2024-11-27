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

#include <unistd.h>

// Yığından bir öğeyi A'ya taşır (pa)
void pa(t_stack **a, t_stack **b)
{
    if (*b) // Eğer B boş değilse
    {
        t_stack *temp = *b;     // B'nin ilk öğesini geçici olarak sakla
        *b = (*b)->next;        // B'nin başını bir sonraki öğeye ilerlet
        temp->next = *a;        // Taşınan öğeyi A'nın başına ekle
        *a = temp;              // A'nın başı artık taşınan öğe
        write(1, "pa\n", 3);    // İşlem adını yazdır
    }
}

// Yığından bir öğeyi B'ye taşır (pb)
void pb(t_stack **a, t_stack **b)
{
    if (*a) // Eğer A boş değilse
    {
        t_stack *temp = *a;     // A'nın ilk öğesini geçici olarak sakla
        *a = (*a)->next;        // A'nın başını bir sonraki öğeye ilerlet
        temp->next = *b;        // Taşınan öğeyi B'nin başına ekle
        *b = temp;              // B'nin başı artık taşınan öğe
        write(1, "pb\n", 3);    // İşlem adını yazdır
    }
}


// Hem A hem de B yığınlarını bir pozisyon aşağı kaydırır (rrr)
void rrr(t_stack *a, t_stack *b)
{
    rra(&a);
    rrb(&b);
	write(1, "rrr\n", 4);
}
