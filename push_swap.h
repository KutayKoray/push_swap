/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:40:51 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/04 15:47:54 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
	int				a_size;
	int				b_size;
}					t_stack;

void				sa(t_node *a);
void				sb(t_node *b);
void				ss(t_node *a, t_node *b);
void				pa(t_stack *stack);
void				pb(t_stack *stack);
void				ra(t_node *a);
void				rb(t_node **b);
void				rr(t_node *a, t_node *b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node *a, t_node *b);

int					is_sorted(t_node *a);
int					stack_size(t_node *stack);
void				sort_three(t_stack *stack);
void				bubble_sort(t_node *stack);
int					get_median(t_node *node, int size);
void				sort_a(t_stack *stack, int len);
void				sort_b(t_stack *stack, int len);
void				sort_init(t_stack *stack, int len);
void				print_node(t_node *stack);

#endif
