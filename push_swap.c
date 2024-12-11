#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void print_data(t_data *data)
{
	int i;

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

int main()
{
	t_data *data;
	int arr[] = {58, 43, 80, 34, 4, 16, 61, 6, 42};
	// sorted_arr = {4, 6, 16, 34, 42, 43, 58, 61, 80}
	int i;

	data = malloc(sizeof(t_data));
	data->arr = arr;
	data->size = 9;
	data->up = -1;
	data->down = 0;

	int	*tmp_arr = bubble_sort(data->arr, data->size);
	int *new_arr = replace(data->arr, tmp_arr, data->size);
	data->arr = new_arr;
	print_data(data);
	radix(data);
	print_data(data);
}

// error handling 
// init stack