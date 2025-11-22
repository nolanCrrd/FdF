/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_region_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:50:21 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/21 11:51:04 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/**
 * @brief Return the point on the right of the given one
 *
 * @param map Concerned map
 * @param origin Concerned point
 * @return Correct point / NULL if not present
 */
t_point	*get_right_point(t_map *map, t_point *origin)
{
	int	cible_x;
	int	cible_y;

	cible_x = origin->x + 1;
	cible_y = origin->y;
	if (cible_x < map->map_width && cible_x >= 0)
		return (map->lst[cible_y * map->map_width + cible_x]);
	return (NULL);
}

/**
 * @brief Return the point on the left of the given one
 *
 * @param map Concerned map
 * @param origin Concerned point
 * @return Correct point / NULL if not present
 */
t_point	*get_up_point(t_map *map, t_point *origin)
{
	int	cible_x;
	int	cible_y;

	cible_x = origin->x;
	cible_y = origin->y - 1;
	if (cible_y < map->map_height - 1 && cible_y >= 0)
		return (map->lst[cible_y * map->map_width + cible_x]);
	return (NULL);
}

/**
 * @brief Give the correct value of the colro between two other based on
 * the advencement in the shade
 *
 * @param origin Origin color
 * @param dest Final color of the shade
 * @param step Advecement in the shade
 * @param nb_step Number of step in total
 * @return Correct shade
 */
unsigned long	get_color_smooth(unsigned long origin, unsigned long dest,
	int step, int nb_step)
{
	float			origin_chanel;
	float			dest_chanel;
	float			result;
	unsigned long	color;

	if (step > nb_step)
		step = nb_step;
	color = 0;
	origin_chanel = (float)((origin >> 24) & 0xFF);
	dest_chanel = (float)((dest >> 24) & 0xFF);
	result = origin_chanel + (dest_chanel - origin_chanel)
		* ((float)step / (float)nb_step);
	color = (color << 8) | ((unsigned char)result);
	origin_chanel = (float)((origin >> 16) & 0xFF);
	dest_chanel = (float)((dest >> 16) & 0xFF);
	result = origin_chanel + (dest_chanel - origin_chanel)
		* ((float)step / (float)nb_step);
	color = (color << 8) | ((unsigned char)result);
	origin_chanel = (float)((origin >> 8) & 0xFF);
	dest_chanel = (float)((dest >> 8) & 0xFF);
	result = origin_chanel + (dest_chanel - origin_chanel)
		* ((float)step / (float)nb_step);
	color = (color << 8) | ((unsigned char)result);
	color = (color << 8) | 0xFF;
	return (color);
}
