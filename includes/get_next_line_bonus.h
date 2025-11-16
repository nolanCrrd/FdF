/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:56 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/24 16:07:33 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

typedef struct s_gnl_list
{
	int					fd;
	char				*buffer;
	char				*line;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
size_t		strlen_til(char	*str, char c);
int			is_line_finished(char *str);
t_gnl_list	*new_gnl_list(int fd);
void		remove_line(char buffer[BUFFER_SIZE + 1], int index);

#endif