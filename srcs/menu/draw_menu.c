/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:44:09 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/24 21:04:04 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	draw_keymap(t_update_info *mlx, mlx_color color)
{
	mlx_set_font_scale(*mlx->mlx, "default", 20.0);
	mlx_string_put(*mlx->mlx, *mlx->win, 130, 40, color, "Keymaps");
	mlx_set_font_scale(*mlx->mlx, "default", 16.0);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 100, color, "Arrow: Rotate x/y");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 140, color, "w/s: Rotate z");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 180, color, "+/-: Zoom");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 220, color, "[/]: Edit height");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 260, color, "scaling");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 300, color, "h/j/k/l: Move");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 340, color, "1-4: Iso sides");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 380, color, "5: Up view");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 420, color, "6: Side view");
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 460, color, "o: toggle menu");
}

void	draw_menu(t_update_info *mlx)
{
	mlx_color	menu_pixels[WIN_H * MENU_W];
	int			i;
	mlx_color	color;

	i = 0;
	while (i < WIN_H * MENU_W)
		menu_pixels[i++] = (mlx_color){.rgba = 0x444444FF};
	mlx_pixel_put_region(*mlx->mlx, *mlx->win, 0, 0,
		MENU_W, WIN_H, menu_pixels);
	color = (mlx_color){.rgba = 0xffffffff};
	draw_keymap(mlx, color);
	write_map_info(mlx, color);
}
