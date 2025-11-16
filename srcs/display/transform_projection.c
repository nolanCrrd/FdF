/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:24:52 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/16 18:56:04 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	scale_projection(t_map *map)
{
	int	scale_x;
	int	scale_y;
	
	// Prendre 80% de l'écran pour laisser des marges
	scale_x = (WIN_W * 0.8) / map->map_width;
	scale_y = (WIN_H * 0.8) / map->map_height;
	
	// Prendre le plus petit des deux pour que tout rentre
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}

int	get_shift_x(t_map *map)
{
	int	x_min;
	int	i;

	i = 0;
	x_min = map->lst[i++]->x;
	while (map->lst[i])
	{
		if (map->lst[i]->x < x_min)
			x_min = map->lst[i]->x;
		i++;
	}
	return (x_min);
}

void	tranform_isometric(t_map *map)
{
	int	i;
	int	new_x;
	int	new_y;
	int	scale;

	i = 0;
	scale = scale_projection(map);
	while (map->lst[i])
	{
		new_x = (map->lst[i]->x - map->lst[i]->y) ;
		new_y = ((map->lst[i]->x + map->lst[i]->y) / 2 - map->lst[i]->altitude);
		map->lst[i]->x = new_x * scale;
		map->lst[i]->y = new_y * scale;
		i++;
	}
}
