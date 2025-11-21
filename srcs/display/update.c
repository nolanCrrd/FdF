/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:51:55 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/21 12:06:20 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdlib.h>

static void	update_map_projection(t_update_info *mlx)
{
	if (mlx->angle_x_move != 0 || mlx->angle_z_move != 0
		|| mlx->angle_y_move != 0 || mlx->preset_changed)
	{
		mlx->map->angle_x += mlx->angle_x_move * (mlx->move_modifier
				* MODIFIER_SPEED + 1);
		mlx->map->angle_y += mlx->angle_y_move * (mlx->move_modifier
				* MODIFIER_SPEED + 1);
		mlx->map->angle_z += mlx->angle_z_move * (mlx->move_modifier
				* MODIFIER_SPEED + 1);
		update_projection(mlx->map);
		mlx->to_update = 1;
		mlx->preset_changed = 0;
	}
}

static void	update_map_move(t_update_info *mlx)
{
	int	i;

	if (mlx->y_move != 0 || mlx->x_move != 0 || mlx->scale_move != 0)
	{
		mlx->map->x_offset += mlx->x_move * (mlx->move_modifier
				* MODIFIER_SPEED + 1);
		mlx->map->y_offset += mlx->y_move * (mlx->move_modifier
				* MODIFIER_SPEED + 1);
		if (mlx->map->scaling + mlx->scale_move > 0)
			mlx->map->scaling += mlx->scale_move * (mlx->move_modifier
					* MODIFIER_SPEED + 1);
		i = -1;
		while (mlx->map->lst[++i])
		{
			mlx->map->lst[i]->screen_x = mlx->map->lst[i]->proj[3][X]
				* mlx->map->scaling + mlx->map->x_offset;
			mlx->map->lst[i]->screen_y = mlx->map->lst[i]->proj[3][Y]
				* mlx->map->scaling + mlx->map->y_offset;
		}
		mlx->to_update = 1;
	}
}

static void	update_map(t_update_info *mlx)
{
	update_map_projection(mlx);
	update_map_move(mlx);
}

void	update(void *mlxv)
{
	t_update_info	*mlx;

	mlx = (t_update_info *) mlxv;
	if (mlx->to_switch_color)
		switch_map_color(mlx->map);
	update_map(mlx);
	if (mlx->to_update || mlx->to_switch_color)
	{
		mlx->to_switch_color = 0;
		mlx->to_update = 0;
		free(mlx->pixels);
		mlx->pixels = get_all_pixel(mlx->map);
		mlx_clear_window(*mlx->mlx, *mlx->win, (mlx_color){.rgba = 0});
		mlx_pixel_put_region(*mlx->mlx, *mlx->win, 0, 0,
			WIN_W, WIN_H, mlx->pixels);
	}
}
