/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:44:14 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 15:51:15 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:26:03 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/22 12:48:42y ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>

enum	e_err_code
{
	E_WRITING_ERR = -1,
};

// Utils
size_t	ft_strlen2(char *str);
void	ft_bzero2(void *ptr, size_t len);

// Converters
char	*ft_lltoa(long long nbr);
char	*ft_ulltoa(unsigned long long nbr);
char	*ft_xtoa(unsigned int nbr, int is_upper);
char	*ft_addtoa(unsigned long long addr);
char	*get_str_or_null(char	*str);

// ft_printf
int		ft_dprintf(int fd, const char *fmt, ...)__attribute__((format(printf, 2, 3)));
int		ft_printf(const char *fmt, ...)__attribute__((format(printf, 1, 2)));

#endif