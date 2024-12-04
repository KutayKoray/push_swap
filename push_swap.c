/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:47:02 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/04 18:28:28 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Yığın içeriğini ekrana yazdırma fonksiyonu
void	print_node(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

// Argümanları stack'e ekleme fonksiyonu
t_node	*create_stack(int argc, char **argv)
{
	t_node	*stack;
	t_node	*temp;
	int		i;

	i = 1;
	stack = (t_node *)malloc(sizeof(t_node));
	stack->value = atoi(argv[i]);
	stack->next = NULL;
	i++;
	while (i < argc)
	{
		temp = (t_node *)malloc(sizeof(t_node));
		temp->value = atoi(argv[i]);
		temp->next = stack;
		stack = temp;
		i++;
	}
	return (stack);
}

// Stack'te eleman sayısı sayma
int	stack_size(t_node *stack)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	get_last_value(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

int	is_sorted(t_node *a)
{
	t_node	*tmp;

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

void sort(t_stack *stack, int size)
{
	if (!is_sorted(stack->a))
	{
		if (size == 2)
			sa(stack->a);
		else if (size == 3)
			sort_three(stack);
		else
			sort_init(stack, size);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack->a = create_stack(argc, argv);
	stack->b = malloc(sizeof(t_node));
	stack->a_size = stack_size(stack->a);
	stack->b_size = 0;
	
	// printf("a: \n");
	// printf("%d\n", stack->a_size);
	// printf("%d: \n", is_sorted(stack->a));

	sort(stack, stack->a_size);	


	// print_node(stack->a);
	// print_node(stack->b);

	


	


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