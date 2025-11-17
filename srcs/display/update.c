/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:51:55 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/17 11:52:52 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libs/MacroLibX-master/includes/mlx.h"

void	update_map_proj(t_map *map, int scale_update, int x_update, int y_update)
{
	map->x_offset += x_update;
	map->y_offset += y_update;
	if (map->scaling + scale_update > 0)
		map->scaling += scale_update;
}

void	update(void *mlxv)
{
	t_update_info	*mlx;
	int	i;
	int	x;
	int	y;

	mlx = (t_update_info *) mlxv;
	i = 0;
	mlx_clear_window(*mlx->mlx, *mlx->win, (mlx_color) {.rgba = 0});
	while (mlx->map->lst[i])
	{
		x = (mlx->map->lst[i]->proj_x + mlx->map->x_offset) * mlx->map->scaling;
		y = (mlx->map->lst[i]->proj_y + mlx->map->y_offset) * mlx->map->scaling;
		if (mlx->map->lst[i]->color)
		{
			mlx_pixel_put(*mlx->mlx, *mlx->win, x, y,
					(mlx_color){ .rgba = mlx->map->lst[i]->color });
		}
		else
		{
			mlx_pixel_put(*mlx->mlx, *mlx->win, x, y,
					(mlx_color){ .rgba = 0xFFFFFFFF});
		}
		i++;
	}
}

