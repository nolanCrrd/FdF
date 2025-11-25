/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:02:26 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/25 10:36:29 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/libft.h"
#include <stdlib.h>

static void	init_window_info(mlx_window_create_info *info)
{
	ft_bzero(info, sizeof(*info));
	info->title = "FdF";
	info->width = WIN_W;
	info->height = WIN_H;
}

static void	set_all_hook(mlx_context *mlx, mlx_window *win,
	t_update_info *update_info)
{
	mlx_add_loop_hook(*mlx, update, update_info);
	mlx_on_event(*mlx, *win, MLX_KEYDOWN, all_hook, update_info);
	mlx_on_event(*mlx, *win, MLX_KEYUP, stop_move_hook, update_info);
	mlx_on_event(*mlx, *win, MLX_WINDOW_EVENT, window_close_hook, *mlx);
}

void	open_window(t_map *map)
{
	mlx_context				mlx;
	mlx_window				win;
	t_update_info			update_info;
	mlx_window_create_info	info;
	mlx_image				img;

	mlx = mlx_init();
	init_window_info(&info);
	win = mlx_new_window(mlx, &info);
	img = mlx_new_image(mlx, WIN_W, WIN_H);
	init_update_info(&update_info);
	update_info.map = map;
	update_info.mlx = &mlx;
	update_info.win = &win;
	update_info.img = &img;
	update_info.pixels = get_all_pixel(map,
			update_info.show_vertical, update_info.show_horizontal);
	mlx_set_fps_goal(mlx, 120);
	set_all_hook(&mlx, &win, &update_info);
	mlx_loop(mlx);
	free(update_info.pixels);
	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, win);
	mlx_destroy_context(mlx);
}
