/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:29:31 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 15:08:53by ncorrear         ###   ########.fr       */
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
		ft_dprintf(2, "fdf: %s: No such file or directory", path);
	return (fd);
}

static int	get_index_from_val(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		s++;
	}
	return (i);
}

int	get_altitude_from_string(char *altitude)
{
	int	converted;
	int				i;

	i = 0;
	converted = 0;
	while (altitude[i])
	{
		converted = converted * 10 + altitude[i] - '0';
		i++;
	}
	return (converted);
}

unsigned long get_color_from_string(char *color)
{
	unsigned long	converted;
	char			*base;
	int				i;

	if (color == NULL)
		return (0);
	base = "0123456789ABCDEF";
	i = 0;
	converted = 0;
	while (color[i])
	{
		converted = converted * 16 + (
			get_index_from_val(ft_toupper(color[i]), base));
		i++;
	}
	return (converted);
}

int	add_point_list(t_point ***list, char **point_info, int x, int y)
{
	int		i;
	t_point	**new_lst;
	t_point *new_point;

	i = 0;
	while (list && list[i])
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
