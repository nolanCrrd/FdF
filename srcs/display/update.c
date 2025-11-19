/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:51:55 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/18 11:34:50 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdlib.h>

void	update(void *mlxv)
{
	t_update_info	*mlx;
	int	i;
	mlx_color	*pixels;

	mlx = (t_update_info *) mlxv;
	i = 0;
	mlx->map->x_offset += mlx->x_move + mlx->move_modifier * MODIFIER_SPEED;
	mlx->map->y_offset += mlx->y_move + mlx->move_modifier * MODIFIER_SPEED;
	mlx->map->scaling += mlx->scale_move;
	if (mlx->map->scaling < 0.1)
		mlx->map->scaling = 0.1;
	mlx->map->z_scaling += mlx->z_scale_move;
	if (mlx->map->z_scaling < 1)
		mlx->map->z_scaling = 1;
	mlx->map->eye_height += mlx->eye_move;
	if (mlx->map->eye_height > 40)
		mlx->map->eye_height = 40;
	if (mlx->map->eye_height < -10)
		mlx->map->eye_height = -10;
	if (mlx->z_scale_move != 0 || mlx->eye_move != 0)
		tranform_isometric(mlx->map);
	while (mlx->map->lst[i])
	{
		mlx->map->lst[i]->screen_x = (mlx->map->lst[i]->proj_x) * mlx->map->scaling + mlx->map->x_offset;
		mlx->map->lst[i]->screen_y = (mlx->map->lst[i]->proj_y) * mlx->map->scaling + mlx->map->y_offset;
		i++;
	}
	free(mlx->pixels);
	mlx->pixels = get_all_pixel(mlx->map);
	mlx_clear_window(*mlx->mlx, *mlx->win, (mlx_color) {.rgba = 0});
	mlx_pixel_put_region(*mlx->mlx, *mlx->win, 0, 0, WIN_W, WIN_H, mlx->pixels);
}

