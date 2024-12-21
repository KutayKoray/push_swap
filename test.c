#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "push_swap.h"

int main()
{
	t_data	*data = malloc(sizeof(t_data));
	int dst[] = {1, 2, 0, 4};
	data->arr = dst;
	data->size = 4;
	data->up = -1;
	data->down = 0;
	printf("%d", is_sorted(data, 'a'));
}