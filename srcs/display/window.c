/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:02:26 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/17 12:40:46 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libs/MacroLibX-master/includes/mlx.h"

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
	mlx_add_loop_hook(mlx, update, &update_info);
	mlx_on_event(mlx, win, MLX_KEYDOWN, move_hook, &update_info);
	mlx_on_event(mlx, win, MLX_KEYDOWN, close_hook, mlx);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, win);
    mlx_destroy_context(mlx);
}
