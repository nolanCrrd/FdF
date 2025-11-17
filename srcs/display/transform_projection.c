/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:24:52 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/16 22:33:55 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	tranform_isometric(t_map *map)
{
	int	i;
	int	new_x;
	int	new_y;
	int	scale;

	i = 0;
	scale = 1;
	while (map->lst[i])
	{
		map->lst[i]->proj_x = (map->lst[i]->x - map->lst[i]->y) ;
		map->lst[i]->proj_y = ((map->lst[i]->x + map->lst[i]->y) / 2 - map->lst[i]->altitude);
		i++;
	}
}
