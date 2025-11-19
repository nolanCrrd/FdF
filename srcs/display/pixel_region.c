/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_region.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:07:41 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/18 11:53:21 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/libft.h"
#include <math.h>
#include <stdio.h>

t_point	*get_right_point(t_map *map, t_point *origin)
{
	int	i;
	int	cible_x;
	int	cible_y;

	cible_x = origin->x + 1;
	cible_y = origin->y;
	if (cible_x < map->map_width && cible_x >= 0)
		return (map->lst[cible_y * map->map_width + cible_x]);
	return (NULL);
}

t_point	*get_up_point(t_map *map, t_point *origin)
{
	int	i;
	int	cible_x;
	int	cible_y;

	cible_x = origin->x;
	cible_y = origin->y - 1;
	if (cible_y < map->map_height - 1 && cible_y >= 0)
		return (map->lst[cible_y * map->map_width + cible_x]);
	return (NULL);
}

void	add_line(t_map *map, mlx_color *pixels, t_point *origin, t_point *dest)
{
	float	current_x;
	float	current_y;
	float	delt_x;
	float	delt_y;
	float	x_inc;
	float	y_inc;
	int		nb_step;

	current_x = origin->screen_x;
	current_y = origin->screen_y;
	delt_x = dest->screen_x - current_x;
	delt_y = dest->screen_y - current_y;
	if (ABS(delt_y) <= ABS(delt_x))
	{
		nb_step = ABS(delt_x);
		x_inc = 1 * ((delt_x < 0) * -2 + 1);
		y_inc = delt_y / nb_step;
	}
	else
	{
		nb_step = ABS(delt_y);
		x_inc = delt_x / nb_step;
		y_inc = 1 * ((delt_y < 0) * -2 + 1);
	}
	while (nb_step > 0)
	{
		if (current_y >= 0 && current_x >= 0 && current_x < WIN_W && current_y < WIN_H
			&& round(current_y) * WIN_W + round(current_x) < WIN_W * WIN_H)
			pixels[(int)(round(current_y) * WIN_W + round(current_x))] = (mlx_color){ .rgba = dest->color };
		current_x += x_inc;
		current_y += y_inc;
		nb_step--;
	}
}

void	add_line_pixels(t_map *map, mlx_color *pixels)
{
	int		i;
	t_point	*cible;

	i = 0;
	while (map->lst[i])
	{
		cible = get_right_point(map, map->lst[i]);
		if (cible)
			add_line(map, pixels, map->lst[i], cible);
		cible = get_up_point(map, map->lst[i]);
		if (cible)
			add_line(map, pixels, map->lst[i], cible);
		i++;
	}
}

/**
 * @brief Generate the array that contain all the pixel to display
 *
 * @param map map information
 * @return Pixels to dislay
 */
mlx_color	*get_all_pixel(t_map *map)
{
	mlx_color	*pixels;
	int			i;
	int			to_draw;
	int			screen_x;
	int			screen_y;

	pixels = ft_calloc(WIN_W * WIN_H, sizeof(mlx_color));
	i = 0;
	add_line_pixels(map, pixels);
	while (map->lst[i])
	{
		to_draw = 1;
		screen_x = map->lst[i]->screen_x;
		screen_y = map->lst[i]->screen_y;
		if (screen_x > WIN_W || screen_y > WIN_H || screen_x < 0 || screen_y < 0
				|| screen_x + screen_y * WIN_W > WIN_H * WIN_W - 1)
			to_draw = 0;
		if (to_draw)
			pixels[screen_y * WIN_W + screen_x] = (mlx_color) { .rgba = map->lst[i]->color };
		i++;
	}
	return (pixels);
}
