/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:25:32 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/17 12:50:34 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libs/MacroLibX-master/includes/mlx.h"
#include "../libs/MacroLibX-master/includes/mlx_extended.h"
#include <math.h>

typedef struct s_point
{
	int				x;
	int				y;
	int				proj_x;
	int				proj_y;
	int				altitude;
	unsigned long	color;
}	t_point;

typedef struct s_map
{
	t_point **lst;
	int		map_width;
	int		map_height;
	int		x_offset;
	int		y_offset;
	int		scaling;
}	t_map;

typedef struct s_update_info
{
	mlx_context	*mlx;
	mlx_window	*win;
	t_map		*map;
}	t_update_info;

#  define ISO_ANGLE (30.0 * M_PI / 180)
#  define WIN_H 800
#  define WIN_W 1200
#  define KEY_ESC 41
#  define KEY_h 11
#  define KEY_j 13
#  define KEY_k 14
#  define KEY_l 15
#  define KEY_plus 46
#  define KEY_minus 45

int	open_file(char	*path);
int	get_altitude_from_string(char *altitude);
unsigned long get_color_from_string(char *color);
int	add_point_list(t_point **list, char **point_info, int x, int y);
int	generate_point_list(t_map *map, int fd);
void	clear_point_lst(t_point **lst);
int	get_number_point(int fd);


void	tranform_isometric(t_map *map);
void	update(void *mlxv);
void	update_map_proj(t_map *map, int scale_update, int x_update, int y_update);
void	move_hook(int key, void *update_info);
void	close_hook(int key, void *mlx);
void	open_window(t_map map);

#endif
