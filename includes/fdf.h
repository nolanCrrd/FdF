/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:25:32 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 15:41:00 by ncorrear         ###   ########.fr       */
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

int	open_file(char	*path);
int	get_altitude_from_string(char *altitude);
unsigned long get_color_from_string(char *color);
int	add_point_list(t_point ***list, char **point_info, int x, int y);
t_point	**generate_point_list(char *file_path);

#endif