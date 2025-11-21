/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:25:32 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/21 12:05:39 by ncorrear         ###   ########.fr       */
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
	int				proj[4][3];
	int				screen_x;
	int				screen_y;
	int				altitude;
	unsigned long	color;
	unsigned long	second_color;
}	t_point;

typedef struct s_map
{
	t_point **lst;
	int		map_width;
	int		map_height;
	int		map_max_altitude;
	int		map_min_altitude;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		x_offset;
	int		y_offset;
	float	scaling;
}	t_map;

typedef struct s_update_info
{
	mlx_context	*mlx;
	mlx_window	*win;
	t_map		*map;
	int		x_move;
	int		y_move;
	int		move_modifier;
	float	angle_x_move;
	float	angle_y_move;
	float	angle_z_move;
	float	scale_move;
	int		to_switch_color;
	int		to_update;
	int		preset_changed;
	mlx_color	*pixels;
}	t_update_info;

#  define WIN_H 1080
#  define WIN_W 1920

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
#  define KEY_LEFT 80
#  define KEY_RIGHT 79
#  define KEY_TAB 43
#  define KEY_1 30
#  define KEY_2 31
#  define KEY_3 32
#  define KEY_4 33
#  define KEY_5 34
#  define KEY_6 35
#  define KEY_7 36
#  define KEY_8 37
#  define KEY_9 38
#  define KEY_0 39

#  define ABS(x) (x) * (((x) < 0) * -2 + 1)
#  define RAD(x) ((x) * M_PI / 180)
#  define DEFAULT_COLOR 0x22A836FF
#  define MIN_COLOR 0x112a7aFF
#  define ZERO_COLOR 0x6bad34FF
#  define BLACK_COLOR 0x6bad34FF
#  define MID_COLOR 0xc78316FF
#  define MAX_COLOR 0x752502FF

#  define X 0
#  define Y 1
#  define Z 2

#  define MOVE_SPEED 2
#  define MODIFIER_SPEED 2

// Parsing
int				open_file(char	*path);
void			parsing_opti(t_map *map, int fd);
int				get_altitude_from_string(char *altitude);
unsigned long 	get_color_from_string(char *color);
t_point			*get_first_point(char *parsed_line);
int				get_number_point(int fd);

// Struct management
unsigned long	get_color_smooth(unsigned long origin,
							   unsigned long dest, int step, int nb_step);
void			clear_point_lst(t_point **lst);
void			init_update_info(t_update_info *update_info);
void			map_init(t_map *map);
void			map_fill_relief_color(t_map *map);
void			switch_map_color(t_map *map);

// Prepare 3D
void			update_projection(t_map *map);
void			set_preset(t_update_info *mlx, float angle_x,
				  float angle_y, float angle_z);

// Prepare display
t_point			*get_right_point(t_map *map, t_point *origin);
t_point			*get_up_point(t_map *map, t_point *origin);
void			draw_all_line(t_update_info *mlx);
mlx_color		*get_all_pixel(t_map *map);

// Display
void			update(void *mlxv);
void			open_window(t_map *map);

// Keyboard event
void			move_hook(int key, void *update_info);
void			stop_move_hook(int key, void *update_info);
void			close_hook(int key, void *mlx);
void			window_close_hook(int event, void* mlx);

#endif
