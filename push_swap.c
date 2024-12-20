#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_data(t_data *data) // silinecek
{
	int	i;

	i = 0;
	printf("arr: [");
	while (i < data->size)
	{
		printf(" %d", data->arr[i]);
		if (i == data->up)
			printf(" |");
		i++;
	}
	printf(" ]\n");
	printf("up: %d\n", data->up);
	printf("down: %d\n", data->down);
}

static int get_argv_size(int argc, char **argv)
{
	int size;
	char **tmp_arr;

	if (argc == 2)
	{
		size = 0;
		tmp_arr = ft_split(argv[1], ' ');
		while (tmp_arr[++size]);
		free_str(tmp_arr);
	}
	else
		size = argc - 1;

	return (size);
}

static int	*init_arr(int argc, char **argv)
{
	char	**tmp_arr;
	int		i;
	int		size;
	int		*arr;

	if (argc == 2)
	{
		tmp_arr = ft_split(argv[1], ' ');
		size = get_argv_size(argc, argv);
	}
	else
	{
		tmp_arr = argv + 1;
		size = argc - 1;
	}
	arr = malloc(sizeof(int) * size);
	i = -1;
	while (tmp_arr[++i])
		arr[i] = ft_atoi(tmp_arr[i]);
	if (argc == 2)
		free_str(tmp_arr);
	return (arr);
}

static void sort_init(t_data *data)
{
	int	*tmp_arr;
	int	*new_arr;

	tmp_arr = bubble_sort(data->arr, data->size);
	new_arr = replace(data->arr, tmp_arr, data->size);
	data->arr = new_arr;
	free(tmp_arr);
	if (is_sorted(data) || data->size == 1)
		return ;
	else if (data->size == 2)
		swap(data, 'a');
	else if (data->size == 3)
		sort_three(data);
	else if (data->size == 4)
		sort_four_and_five(data, 4);
	else if (data->size == 5)
		sort_four_and_five(data, 5);
	else
		radix(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (-1);
	check_arg(argc, argv);
	data = malloc(sizeof(t_data));
	data->arr = init_arr(argc, argv);
	data->size = get_argv_size(argc, argv);
	data->up = -1;
	data->down = 0;
    // print_data(data);
	sort_init(data);
	// print_data(data);
	free(data->arr);
}

// error handling
// init stack
// static fonksiyonlara bak norm bak