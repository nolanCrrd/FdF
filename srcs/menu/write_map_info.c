/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:39:25 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/24 21:06:14 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/libft.h"
#include <stdlib.h>

static char	*strjoin_float(char *txt, float x)
{
	char	*tmp;
	char	*total;

	total = ft_strjoin(txt, ft_itoa(x));
	tmp = ft_strjoin(total, ",");
	free(total);
	total = ft_strjoin(tmp, ft_itoa((int)(x * 100) % 100));
	free(tmp);
	return (total);
}

static void	write_static_val(t_update_info *mlx, mlx_color color)
{
	char	*txt;

	txt = strjoin_float("Map width: ", mlx->map->map_width);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 940, color, txt);
	free(txt);
	txt = strjoin_float("Map height: ", mlx->map->map_height);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 980, color, txt);
	free(txt);
	txt = strjoin_float("Max height: ", mlx->map->map_max_altitude);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 1020, color, txt);
	free(txt);
	txt = strjoin_float("Min height: ", mlx->map->map_min_altitude);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 1060, color, txt);
	free(txt);
}

static void	write_map_projection_info(t_update_info *mlx, mlx_color color)
{
	char	*txt;

	txt = strjoin_float("Angle x: ", fmod(mlx->map->angle_x, 360.0f));
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 740, color, txt);
	free(txt);
	txt = strjoin_float("Angle y: ", fmod(mlx->map->angle_y, 360.0f));
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 780, color, txt);
	free(txt);
	txt = strjoin_float("Angle z: ", fmod(mlx->map->angle_z, 360.0f));
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 820, color, txt);
	free(txt);
}

void	write_map_info(t_update_info *mlx, mlx_color color)
{
	char	*txt;

	mlx_set_font_scale(*mlx->mlx, "default", 20.0);
	mlx_string_put(*mlx->mlx, *mlx->win, 100, 600, color, "Map Infos");
	mlx_set_font_scale(*mlx->mlx, "default", 16.0);
	txt = strjoin_float("Offset x: ", mlx->map->x_offset);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 660, color, txt);
	free(txt);
	txt = strjoin_float("Offset y: ", mlx->map->y_offset);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 700, color, txt);
	free(txt);
	write_map_projection_info(mlx, color);
	txt = strjoin_float("Scaling: ", mlx->map->scaling);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 860, color, txt);
	free(txt);
	txt = strjoin_float("Scaling z: ", mlx->map->z_scaling);
	mlx_string_put(*mlx->mlx, *mlx->win, 20, 900, color, txt);
	free(txt);
	write_static_val(mlx, color);
}
