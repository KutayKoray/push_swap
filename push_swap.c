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

	i = 0;
	if (argc == 2 && --i)
	{
		tmp_arr = ft_split(argv[1], ' ');
		size = get_argv_size(argc, argv);
	}
	else
	{
		tmp_arr = argv;
		size = argc - 1;
	}
	arr = malloc(sizeof(int) * size);
	while (tmp_arr[++i])
		arr[i - 1] = ft_atoi(tmp_arr[i]);
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

	radix(data);
	// print_data(data);
}

// error handling
// init stack
// static fonksiyonlara bak norm bak