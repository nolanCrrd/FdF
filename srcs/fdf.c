/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:24:38 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/25 11:49:19 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdlib.h>

static int	check_valid(int argc, char **argv)
{
	int	fd;
	int	nb_point;

	if (argc != 2)
	{
		ft_dprintf(2, "fdf: 1 argument expected %i given\n", argc - 1);
		exit(1);
	}
	fd = open_file(argv[1]);
	nb_point = get_number_point(fd);
	close(fd);
	if (nb_point < 0)
	{
		ft_dprintf(2, "fdf: Invalid map: It's not rectangular\n");
		exit(1);
	}
	return (nb_point);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	int		nb_point;

	nb_point = check_valid(argc, argv);
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
