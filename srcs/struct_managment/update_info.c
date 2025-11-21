/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:47:31 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/21 10:10:10 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_update_info(t_update_info *update_info)
{
	update_info->to_update = 1;
	update_info->angle_x_move = 0;
	update_info->angle_z_move = 0;
	update_info->angle_y_move = 0;
	update_info->x_move = 0;
	update_info->y_move = 0;
	update_info->move_modifier = 0;
	update_info->scale_move = 0;
	update_info->to_switch_color = 0;
	update_info->preset_changed = 0;
}
