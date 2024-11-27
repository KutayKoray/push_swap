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
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int count = 0;

	while (!is_sorted(*a))
	{
		tmp_a = *a;
		tmp_b = *b;
		while (!is_sorted(*a))
		{
			if ((*a)->value > (*a)->next->value && (*a)->value > get_last_value((*a)))
					sa(*a);
			else if ((*a)->value > (*a)->next->value && (*a)->value < get_last_value((*a)))
					ra(a);
			else if ((*a)->value < (*a)->next->value && (*a)->value > get_last_value((*a)))
					rra(a);
			else if ((*a)->value < (*a)->next->value && (*a)->value < get_last_value((*a)))
					pb(a, b);
			count++;
			if (is_sorted(*a))
				break;
		}
		while (!is_sorted(*b))
		{
			if ((*b)->value > (*b)->next->value && (*b)->value > get_last_value((*b)))
				sb(*b);
			else if ((*b)->value > (*b)->next->value && (*b)->value < get_last_value((*b)))
				rb(b);
			else if ((*b)->value < (*b)->next->value && (*b)->value > get_last_value((*b)))
				rrb(b);
			else if ((*b)->value < (*b)->next->value && (*b)->value < get_last_value((*b)))
				pa(a, b);
			count++;
			if (is_sorted(*b))
				break;
		}
		while (*b)
		{
			rrb(b);
			pa(a, b);
			count += 2;
		}
	}
	printf("count: %d\n", count);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	a = create_stack(argc, argv);

	printf("is_sorted(a): %d\n", is_sorted(a));
	printf("is_sorted(b): %d\n", is_sorted(b));

	print_stack(a);
	print_stack(b);	

	sort_stack(&a, &b);

	print_stack(a);
	print_stack(b);

	// print the first element of the stack a and b
	printf("a->value: %d\n", a->value);


	return (0);
}


/*
• Program, en küçük sayı en üstte olacak şekilde, a stackini sıralamak için gereken
minimum aksiyonların listesini çıktı olarak vermelidir.
• Aksiyonlar yalnızca ’\n’ ile ayrılmalıdır. Başka/Ekstra hiçbir karakter kabul edilmeyecektir.
• Hedef stacki mümkün olan minimum sayıda aksiyon ile sıralamaktır. Değerlendirme
sürecinde programınızın verdiği aksiyon çıktılarını bir limite göre karşılaştırılacaktır:
izin verilen maksimum aksiyon sayısı. Eğer programınız daha uzun bir liste çıktısı
veriyorsa veya integerlar doğru bir şekilde sıralanmamışsa notunuz 0 olacaktır.
• Eğer program çalıştırılırken hiçbir argüman verilmezse, program hiçbir çıktı vermemeli ve çıkış yapmalıdır.
• Herhangi bir hata durumunda, standard error’a "Error" ve takiben ’\n’ çıktısı verilmelidir. Hata örnekleri: bazı argümanların integer olmaması, bazı argümanların
integerdan daha büyük olması ve/veya aynı integerdan birden çok kez bulunması.
*/