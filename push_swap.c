/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:47:02 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/27 17:39:53 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Yığın içeriğini ekrana yazdırma fonksiyonu
void print_stack(t_stack *stack)
{
    t_stack *temp = stack;
    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Argümanları stack'e ekleme fonksiyonu
t_stack *create_stack(int argc, char **argv)
{
    t_stack *stack = NULL;
    t_stack *new_node;
    int i;

    for (i = 1; i < argc; i++)
    {
        new_node = (t_stack *)malloc(sizeof(t_stack));
        if (!new_node)
			return NULL;
        new_node->value = atoi(argv[i]);
        new_node->next = stack;
        stack = new_node;
    }
    return stack;
}

// Stack'te eleman sayısı sayma
int stack_size(t_stack *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int get_last_value(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return stack->value;
}

// Stack'in sıralı olup olmadığını kontrol etme
int is_sorted(t_stack *a)
{
    // Stack boşsa veya tek elemanlıysa, zaten sıralıdır
    if (!a || !a->next)
        return 1;

    // Stack'teki her elemanı kontrol et
    t_stack *tmp = a;
    while (tmp->next)
    {
        // Eğer bir eleman sonraki elemandan büyükse, sıralı değil demektir
        if (tmp->value > tmp->next->value)
            return 0;
        tmp = tmp->next;
    }

    // Eğer tüm elemanlar sıralıysa, 1 döndür
    return 1;
}

void sort_stack(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    
    // A stack'inin sıralanmadığı sürece işlemi devam ettir
    while (!is_sorted(*a)) // A stack'inin sıralı olup olmadığını kontrol et
    {
        tmp = *a;

        // A stack'inde her elemanı kontrol et
        while (tmp && tmp->next)
        {
            // Koşulları kontrol et ve uygun işlemi yap
            if (tmp->value > tmp->next->value && tmp->value < get_last_value(*a))
            {
                sa(*a); // Swap işlemi
            }
            else if (tmp->value < tmp->next->value && tmp->value > get_last_value(*a))
            {
                rra(*a); // Reverse rotate işlemi
            }
            else if (tmp->value < tmp->next->value && tmp->value < get_last_value(*a))
            {
                pb(*a, *b); // Elemanı B'ye gönder
            }
            else
            {
                ra(*a); // Rotate işlemi
            }
            tmp = tmp->next;
        }

        // B stack'ini sıralayıp A'ya geri gönder
        while (!is_sorted(*b)) // B stack'ini sıralayıp A'ya geri gönder
        {
            // B stack'inde tersine işlemleri yaparak A'ya gönder
            if ((*b)->value < get_last_value(*a))
                pa(*a, *b); // B'den A'ya eleman taşır
            else
                rb(*b); // B'yi rotate et
        }

        // A stack'inin sıralanmadığı sürece devam et
        if (is_sorted(*a))
            break; // Eğer A sıralandıysa, işlemi bitir
    }
}


int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

	a = create_stack(argc, argv);

	print_stack(a);
	
	sort_stack(&a, &b);

	print_stack(a);
	print_stack(b);

    return 0;
}
