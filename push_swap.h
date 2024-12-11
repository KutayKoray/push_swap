#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		*replace(int *arr, int *arr_sorted, int size);
int		*bubble_sort(int *arr, int size);
int		stack_len(t_data *data, char label);

void	radix(t_data *data);

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

void	ft_error(void);
void	check_arg(int ac, char **av);

void	free_str(char **str);

#endif