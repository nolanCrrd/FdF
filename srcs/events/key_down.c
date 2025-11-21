/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:07:51 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/20 18:02:20 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	rotate_keys(int key, t_update_info *mlx)
{
	if (key == KEY_UP)
		mlx->angle_x_move = 0.5;
	if (key == KEY_DOWN)
		mlx->angle_x_move = -0.5;
	if (key == KEY_LEFT)
		mlx->angle_y_move = -0.5;
	if (key == KEY_RIGHT)
		mlx->angle_y_move = 0.5;
	if (key == KEY_w)
		mlx->angle_z_move = 0.5;
	if (key == KEY_s)
		mlx->angle_z_move = -0.5;
}

static void	translate_key(int key, t_update_info *mlx)
{
	if (key == KEY_h)
		mlx->x_move = MOVE_SPEED;
	if (key == KEY_l)
		mlx->x_move = -MOVE_SPEED;
	if (key == KEY_k)
		mlx->y_move = MOVE_SPEED;
	if (key == KEY_j)
		mlx->y_move = -MOVE_SPEED;
	if (key == KEY_plus)
		mlx->scale_move = 0.005;
	if (key == KEY_minus)
		mlx->scale_move = -0.005;
	if (key == KEY_SHIFT)
		mlx->move_modifier = 1;
	if (key == KEY_TAB)
		mlx->to_switch_color = 1;
}

static void	view_preset(int key, t_update_info *mlx)
{
	if (key == KEY_1)
		set_preset(mlx, 45, -35, 30);
	if (key == KEY_2)
		set_preset(mlx, 45, 35, -30);
	if (key == KEY_3)
		set_preset(mlx, -45, -35, 150);
	if (key == KEY_4)
		set_preset(mlx, -45, 35, -150);
	if (key == KEY_5)
		set_preset(mlx, 0, 0, 0);
}

void	move_hook(int key, void *update_info)
{
	t_update_info	*mlx;

	mlx = (t_update_info *)update_info;
	rotate_keys(key, mlx);
	translate_key(key, mlx);
	view_preset(key, mlx);
}

void	close_hook(int key, void *mlx)
{
	if (key == KEY_ESC)
		mlx_loop_end((mlx_context) mlx);
}
