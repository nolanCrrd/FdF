/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:25:05 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/25 10:33:26 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"
#include "../../includes/fdf.h"
#include <stdlib.h>

static int	get_line_width(char	*line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' '
				|| line[i + 1] == 0))
			width++;
		i++;
	}
	return (width);
}

int	get_number_point(int fd)
{
	int		nb_point;
	int		prec_width;
	char	*gnl;
	int		width;
	int		i;

	nb_point = 0;
	width = 0;
	prec_width = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		if (nb_point >= 0)
		{
			width = get_line_width(gnl);
			nb_point += width;
			if (width != prec_width && prec_width != 0)
				nb_point = -1;
			else
				prec_width = width;
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (nb_point);
}
