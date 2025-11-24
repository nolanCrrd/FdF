/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:44:09 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/24 14:03:57 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	draw_text(t_update_info *mlx)
{
	mlx_set_font_scale(*mlx->mlx, "default", 20.0);
	mlx_string_put(*mlx->mlx, *mlx->win, 100, 40, (mlx_color){.rgba=0xffffffff}, "Keymaps");
	mlx_set_font_scale(*mlx->mlx, "default", 16.0);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 150, (mlx_color){.rgba=0xffffffff}, "Arrow: Rotate x/y");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 190, (mlx_color){.rgba=0xffffffff}, "w/s: Rotate z");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 270, (mlx_color){.rgba=0xffffffff}, "+/-: Zoom");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 310, (mlx_color){.rgba=0xffffffff}, "[/]: Edit height");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 350, (mlx_color){.rgba=0xffffffff}, "scaling");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 430, (mlx_color){.rgba=0xffffffff}, "h/j/k/l: Move");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 510, (mlx_color){.rgba=0xffffffff}, "1-9: View preset");
}

void	draw_menu(t_update_info *mlx)
{
	mlx_color	menu_pixels[WIN_H * MENU_W];
	int			i;

	i = 0;
	while (i < WIN_H * MENU_W)
		menu_pixels[i++] = (mlx_color){ .rgba = 0x444444FF};
	mlx_pixel_put_region(*mlx->mlx, *mlx->win, 0, 0, MENU_W, WIN_H, menu_pixels);
	draw_text(mlx);
}
