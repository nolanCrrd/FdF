/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:53:52 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/17 12:17:15 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	move_hook(int key, void *update_info)
{
	t_update_info	*mlx;
	int				x_update;
	int				y_update;
	int				scale_update;

	mlx = (t_update_info *)update_info;
	x_update = 0;
	y_update = 0;
	scale_update = 0;
	if (key == KEY_h)
		x_update = -1;
	if (key == KEY_l)
		x_update = 1;
	if (key == KEY_k)
		y_update = -1;
	if (key == KEY_j)
		y_update = 1;
	if (key == KEY_plus)
		scale_update = 1;
	if (key == KEY_minus)
		scale_update = -1;
	update_map_proj(mlx->map, scale_update, x_update, y_update);
}

void	close_hook(int key, void *mlx)
{
	if (key == KEY_ESC)
		mlx_loop_end((mlx_context) mlx);
}
