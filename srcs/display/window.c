/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:02:26 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/18 11:29:35 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdlib.h>

// TODO: Normer
void	open_window(t_map map)
{
    mlx_context mlx = mlx_init();
	int			i;
	t_update_info	update_info;

    mlx_window_create_info info = { 0 };
    info.title = "FdF";
    info.width = WIN_W;
    info.height = WIN_H;
    mlx_window win = mlx_new_window(mlx, &info);
	update_info.map = &map;
	update_info.mlx = &mlx;
	update_info.win = &win;
	update_info.x_move = 0;
	update_info.y_move = 0;
	update_info.move_modifier = 0;
	update_info.scale_move = 0;
	update_info.z_scale_move = 0;
	update_info.eye_move = 0;
	update_info.pixels = get_all_pixel(&map);
	mlx_add_loop_hook(mlx, update, &update_info);
	mlx_on_event(mlx, win, MLX_KEYDOWN, move_hook, &update_info);
	mlx_on_event(mlx, win, MLX_KEYUP, stop_move_hook, &update_info);
	mlx_on_event(mlx, win, MLX_KEYDOWN, close_hook, mlx);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_close_hook, mlx);
	mlx_set_fps_goal(mlx, 120);
    mlx_loop(mlx);
	free(update_info.pixels);
    mlx_destroy_window(mlx, win);
    mlx_destroy_context(mlx);
}
