/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:15:41 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/16 12:33:16 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"
#include <stdlib.h>
#include <fcntl.h>

int	open_file(char	*path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "fdf: %s: No such file or directory", path);
		exit(1);
	}
	return (fd);
}

int	get_altitude_from_string(char *altitude)
{
	int	converted;
	int	i;
	int	sign;

	i = 0;
	converted = 0;
	sign = 1;
	if (altitude[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (altitude[i] && altitude[i] > '0' && altitude[i] < '9')
		converted = converted * 10 + altitude[i++] - '0';
	return (converted * sign);
}

unsigned long	get_color_from_string(char *color)
{
	unsigned long	converted;
	char			*base;
	int				i;

	if (color == NULL)
		return (0);
	base = "0123456789ABCDEF";
	i = 2;
	converted = 0;
	while (color[i] && ft_strchr(base, color[i]) != NULL)
	{
		converted = converted * 16 + (ft_strchr(base, color[i]) - base);
		i++;
	}
	return (converted);
}

int	add_point_list(t_point ***list, char **point_info, int x, int y)
{
	int		i;
	t_point	**new_lst;
	t_point	*new_point;

	i = 0;
	while (list && *list && (*list)[i])
		i++;
	new_point = malloc(sizeof(t_point));
	new_lst = malloc(sizeof(t_point *) * (i + 2));
	if (new_lst == NULL || new_point == NULL)
		return (1);
	i = -1;
	while (list && *list && (*list)[++i])
		new_lst[i] = (*list)[i];
	new_point->x = x;
	new_point->y = y;
	new_point->altitude = get_altitude_from_string(point_info[0]);
	new_point->color = get_color_from_string(point_info[1]);
	if (i == -1)
		i = 0;
	new_lst[i++] = new_point;
	new_lst[i] = NULL;
	free(*list);
	*list = new_lst;
	return (0);
}
