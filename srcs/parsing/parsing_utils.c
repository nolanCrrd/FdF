/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:15:41 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/17 13:26:59 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"
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
	if (color[0] != '0')
		return (DEFAULT_COLOR);
	i = 2;
	converted = 0;
	while (color[i] && ft_strchr(base, color[i]) != NULL)
	{
		converted = converted * 16 + (ft_strchr(base,
										  ft_toupper(color[i])) - base);
		i++;
	}
	if (i != 2)
	{
		converted = converted * 16 + (ft_strchr(base, 'F') - base);
		converted = converted * 16 + (ft_strchr(base, 'F') - base);
	}
	return (converted);
}

int	get_number_point(int fd)
{
	int		nb_tot;
	char	*res;
	int		nb_line;

	res = get_next_line(fd);
	nb_tot = 0;
	nb_line = 0;
	while (res != NULL)
	{
		if (nb_tot == 0)
		{
			while (res[nb_line])
			{
				if (res[nb_line] != ' ' && (res[nb_line + 1] == ' ' || res[nb_line + 1] == 0))
					nb_tot++;
				nb_line++;
			}
			nb_line = 0;
		}
		nb_line += 1;
		free(res);
		res = get_next_line(fd);
	}
	nb_tot = nb_tot * nb_line;
	return (nb_tot);
}

int	add_point_static_lst(t_point **list, t_point *point,int x, int y)
{
	static int	i = 0;

	point->x = x;
	point->y = y;
	list[i++] = point;
	return (0);
}

t_point	*get_first_point(char *parsed_line)
{
	t_point			*point;
	int				i;

	point = malloc(sizeof(t_point));
	if (point == NULL)
		return (point);
	point->altitude = ft_atoi(parsed_line);
	i = 0;
	while (parsed_line[i] && parsed_line[i] != ' ' && parsed_line[i] != ',')
		i++;
	if (parsed_line[i] == ',')
		point->color = get_color_from_string(&parsed_line[i + 1]);
	else
		point->color = get_color_from_string(&parsed_line[i]);
	return (point);
}

