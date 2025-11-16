
#include "../includes/fdf.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	t_point **lst;
	int		i = 0;

	lst = generate_point_list(argv[1]);
	while (lst[i])
	{
		printf("%i, %i, %i, %li\n",
			lst[i]->x, lst[i]->y, lst[i]->altitude, lst[i]->color);
		free(lst[i]);
		i++;
	}
	free(lst);
}