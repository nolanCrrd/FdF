/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:25:32 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/16 17:47:46 by ncorrear         ###   ########.fr       */
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
	int				altitude;
	unsigned long	color;
}	t_point;

typedef struct s_map
{
	t_point **lst;
	int		map_width;
	int		map_height;
}	t_map;

#  define ISO_ANGLE (30.0 * M_PI / 180)
#  define WIN_H 800
#  define WIN_W 1200

int	open_file(char	*path);
int	get_altitude_from_string(char *altitude);
unsigned long get_color_from_string(char *color);
int	add_point_list(t_point ***list, char **point_info, int x, int y);
int	generate_point_list(t_map *map, int fd);
void	clear_point_lst(t_point **lst);


void	tranform_isometric(t_map *map);
void	open_window(t_map map);

#endif
