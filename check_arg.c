/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:33:52 by kkoray            #+#    #+#             */
/*   Updated: 2024/12/21 16:23:02 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_error(int argc, char **str)
{
	if (argc == 2)
		free_str(str);
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (c);
	}
	return (0);
}

static int	ft_isrepeat(long num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atol(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_arg(int ac, char **av)
{
	int		i;
	long	num;
	char	**tab;

	i = 0;
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
		tab = av + 1;
	while (tab[i])
	{
		if (!ft_isnum(tab[i]))
			ft_error(ac, tab);
		num = ft_atol(tab[i]);
		if (ft_isrepeat(num, tab, i))
			ft_error(ac, tab);
		if (num < INT_MIN || num > INT_MAX)
			ft_error(ac, tab);
		i++;
	}
	if (ac == 2)
		free_str(tab);
}
