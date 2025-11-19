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
#include <stdio.h>

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
	if (key == KEY_w)
		mlx->z_scale_move = 0.5;
	if (key == KEY_s)
		mlx->z_scale_move = -0.5;
	if (key == KEY_UP)
		mlx->eye_move += 0.1;
	if (key == KEY_DOWN)
		mlx->eye_move += -0.1;
	if (key == KEY_SHIFT)
		mlx->move_modifier = 1;
}

void	stop_move_hook(int key, void *update_info)
{
	t_update_info	*mlx;

	mlx = (t_update_info *) update_info;
	if (key == KEY_j || key == KEY_k)
		mlx->y_move = 0;
	if (key == KEY_h || key == KEY_l)
		mlx->x_move = 0;
	if (key == KEY_minus || key == KEY_plus)
		mlx->scale_move = 0;
	if (key == KEY_w || key == KEY_s)
		mlx->z_scale_move = 0;
	if (key == KEY_SHIFT)
		mlx->move_modifier = 0;
	if (key == KEY_UP || key == KEY_DOWN)
		mlx->eye_move = 0;
}

void	close_hook(int key, void *mlx)
{
	if (key == KEY_ESC)
		mlx_loop_end((mlx_context) mlx);
}

void window_close_hook(int event, void* mlx)
{
    if(event == 0)
        mlx_loop_end((mlx_context) mlx);
}
