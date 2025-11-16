/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:52 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 11:00:53 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"
#include <stdlib.h>

int	is_line_finished(char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t	strlen_til(char	*str, char c)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

void	remove_line(char buffer[BUFFER_SIZE + 1], int index)
{
	int	i;

	i = 0;
	while (buffer[i] && index <= BUFFER_SIZE)
		buffer[i++] = buffer[index++];
	while (i <= BUFFER_SIZE)
		buffer[i++] = 0;
}

t_gnl_list	*new_gnl_list(int fd)
{
	t_gnl_list	*new;

	new = malloc(sizeof(t_gnl_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->line = NULL;
	new->buffer = malloc(BUFFER_SIZE + 1);
	if (new->buffer == NULL)
	{
		free(new);
		return (NULL);
	}
	new->buffer[0] = 0;
	remove_line(new->buffer, 0);
	new->next = NULL;
	return (new);
}
