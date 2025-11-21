/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:09:00 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/20 09:38:40 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
	if (key == KEY_SHIFT)
		mlx->move_modifier = 0;
	if (key == KEY_UP || key == KEY_DOWN)
		mlx->angle_x_move = 0;
	if (key == KEY_LEFT || key == KEY_RIGHT)
		mlx->angle_y_move = 0;
	if (key == KEY_w || key == KEY_s)
		mlx->angle_z_move = 0;
}
