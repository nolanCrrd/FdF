/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:52:16 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/20 18:00:00 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/**
 * @brief Set all angles of the map to the given values
 *
 * @param mlx All update information
 * @param angle_x New value for angleX
 * @param angle_y same for angleY
 * @param angle_z same for angleZ 
 */
void	set_preset(t_update_info *mlx, float angle_x,
	float angle_y, float angle_z)
{
	mlx->map->angle_z = angle_z;
	mlx->map->angle_y = angle_y;
	mlx->map->angle_x = angle_x;
	mlx->preset_changed = 1;
}
