#include <limits.h>

void	ft_error(void)
{
	write(2, "Error", 5);
	exit(0);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (c);
	}
	return (0);
}

static int	ft_isrepeat(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
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

void	check_args(int ac, char **av)
{
	int i;
	long num;
	char **tab;

	i = 0;
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
	{
		i = 1;
		tab = av;
	}
	while (tab[i])
	{
		if (!ft_isnum(tab[i]))
			ft_error();
		num = ft_atoi(tab[i]);
		if (ft_isrepeat(num, tab, i))
			ft_error();
		if (num < INT_MIN || num > INT_MAX)
			ft_error();
		i++;
	}
	if (ac == 2)
		ft_free_str(tab);
}