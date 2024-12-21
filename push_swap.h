/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:33:35 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/21 16:21:51 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_data
{
	int	*arr;
	int	size;
	int	up;
	int	down;
}		t_data;

void	swap(t_data *data, char label);
void	rotate(t_data *data, char label);
void	reverse_rotate(t_data *data, char label);
void	push(t_data *data, char label);

int		is_full_sorted(t_data *data);
int		is_sorted(t_data *data, char label);
int		*replace(int *arr, int *arr_sorted, int size);
int		*bubble_sort(int *arr, int size);
int		stack_len(t_data *data, char label);
void	radix(t_data *data);
void	sort_three(t_data *data);
void	sort_four_and_five(t_data *data, int size);

long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	check_arg(int ac, char **av);
void	free_str(char **str);
void	ft_error(int ac, char **str);
void	free_data_and_exit(t_data *data);

#endif