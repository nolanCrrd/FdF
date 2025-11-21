/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:24:38 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/16 12:33:58 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	int		i;
	int		nb_point;

	if (argc != 2)
	{
		ft_dprintf(2, "1 argument expected %i given", argc - 1);
		exit(1);
	}
	fd = open_file(argv[1]);
	nb_point = get_number_point(fd);
	fd = open_file(argv[1]);
	map.lst = ft_calloc(nb_point + 2, sizeof(t_point *));
	map_init(&map);
	parsing_opti(&map, fd);
	map.scaling = 80.0f / (map.map_width + map.map_height);
	update_projection(&map);
	map_fill_relief_color(&map);
	open_window(&map);
	clear_point_lst(map.lst);
	return (0);
}
