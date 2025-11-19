/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:25:32 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/18 11:17:10 by ncorrear         ###   ########.fr       */
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
	int				screen_x;
	int				screen_y;
	int				altitude;
	unsigned long	color;
}	t_point;

typedef struct s_map
{
	t_point **lst;
	int		map_width;
	int		map_height;
	int		map_altitude;
	int		x_offset;
	int		y_offset;
	float	z_scaling;
	float	scaling;
	float	eye_height;
}	t_map;

typedef struct s_update_info
{
	mlx_context	*mlx;
	mlx_window	*win;
	t_map		*map;
	int		x_move;
	int		y_move;
	int		move_modifier;
	float	scale_move;
	float	z_scale_move;
	float	eye_move;
	mlx_color	*pixels;
}	t_update_info;

#  define ISO_ANGLE (30.0 * M_PI / 180)
#  define WIN_H 800
#  define WIN_W 1200
#  define KEY_ESC 41
#  define KEY_h 11
#  define KEY_j 13
#  define KEY_k 14
#  define KEY_l 15
#  define KEY_w 26
#  define KEY_s 22
#  define KEY_plus 46
#  define KEY_minus 45
#  define KEY_SHIFT 225
#  define KEY_UP 82
#  define KEY_DOWN 81
#  define ABS(x) (x) * (((x) < 0) * -2 + 1)
#  define DEFAULT_COLOR 0x22a836FF
#  define MOVE_SPEED 2
#  define MODIFIER_SPEED 2

int	open_file(char	*path);
int	get_altitude_from_string(char *altitude);
unsigned long get_color_from_string(char *color);
int	add_point_static_lst(t_point **list, t_point *point,int x, int y);
t_point	*get_first_point(char *parsed_line);
void	parsing_opti(t_map *map, int fd);
void	clear_point_lst(t_point **lst);
int	get_number_point(int fd);


mlx_color	*get_all_pixel(t_map *map);
void	tranform_isometric(t_map *map);
void	draw_all_line(t_update_info *mlx);
void	update(void *mlxv);
void	move_hook(int key, void *update_info);
void	stop_move_hook(int key, void *update_info);
void	close_hook(int key, void *mlx);
void window_close_hook(int event, void* mlx);
void	open_window(t_map map);

#endif
