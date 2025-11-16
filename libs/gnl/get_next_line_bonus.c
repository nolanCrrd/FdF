/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:57:33 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 11:00:53 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

t_gnl_list	*get_list_fd(t_gnl_list *lst, int fd)
{
	t_gnl_list	*new;

	if (lst != NULL)
	{
		while (lst->next && lst->fd != fd)
		{
			if (lst->next->fd == fd)
				return (lst->next);
			lst = lst->next;
		}
		if (lst->fd == fd)
			return (lst);
	}
	new = new_gnl_list(fd);
	if (lst != NULL)
		lst->next = new;
	return (new);
}

void	*remove_fd_list(t_gnl_list **lst, int fd)
{
	t_gnl_list	*current;
	t_gnl_list	*prev;

	current = *lst;
	prev = NULL;
	if (current != NULL)
	{
		while (current && current->fd != fd)
		{
			prev = current;
			current = current->next;
		}
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			if (current == *lst)
				*lst = current->next;
			free(current->buffer);
			free(current->line);
			free(current);
		}
	}
	return (NULL);
}

int	append_line(char **dst, char	*src)
{
	size_t	src_len;
	char	*new_line;
	size_t	i;
	size_t	j;

	src_len = strlen_til(src, '\n');
	if (src[src_len] == '\n')
		src_len++;
	new_line = malloc(strlen_til(*dst, '\0') + src_len + 1);
	if (new_line == NULL)
		return (0);
	j = (*dst != NULL) * -1;
	while (*dst && (*dst)[++j])
		new_line[j] = (*dst)[j];
	i = 0;
	while (src[i] && src[i] != '\n')
		new_line[j++] = src[i++];
	if (src[i] == '\n')
		new_line[j++] = src[i];
	new_line[j] = 0;
	free(*dst);
	*dst = new_line;
	remove_line(src, i + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*buffer_list = NULL;
	t_gnl_list			*current_fd_list;
	int					keep_working;

	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	current_fd_list = get_list_fd(buffer_list, fd);
	if (current_fd_list == NULL)
		return (NULL);
	if (buffer_list == NULL)
		buffer_list = current_fd_list;
	keep_working = 1;
	current_fd_list->line = NULL;
	while (keep_working > 0 && !is_line_finished(current_fd_list->line))
	{
		if (current_fd_list->buffer[0] != 0)
			keep_working = append_line(&current_fd_list->line,
					current_fd_list->buffer);
		else
			keep_working = read(fd, current_fd_list->buffer, BUFFER_SIZE);
	}
	if (!keep_working && current_fd_list->line == NULL
		&& !remove_fd_list(&buffer_list, fd))
		return (NULL);
	return (current_fd_list->line);
}
