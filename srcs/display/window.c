/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:02:26 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/16 18:14:44 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libs/MacroLibX-master/includes/mlx.h"

void	open_window(t_map map)
{
    mlx_context mlx = mlx_init();
	int			i;

    mlx_window_create_info info = { 0 };
    info.title = "Hello World!";
    info.width = WIN_W;
    info.height = WIN_H;
    mlx_window win = mlx_new_window(mlx, &info);
	// Affichage des points
	i = 0;
	while (map.lst[i])
	{
		if (map.lst[i]->color)
		{
			mlx_pixel_put(mlx, win, map.lst[i]->x, map.lst[i]->y,
					(mlx_color){ .rgba = map.lst[i]->color });
		}
		else
		{
			mlx_pixel_put(mlx, win, map.lst[i]->x, map.lst[i]->y,
					(mlx_color){ .rgba = 0xFFFFFFFF});
		}
		i++;
	}
    mlx_loop(mlx);
    mlx_destroy_window(mlx, win);
    mlx_destroy_context(mlx);
}
