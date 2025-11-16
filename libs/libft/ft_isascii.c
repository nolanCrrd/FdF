/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:23:29 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 13:18:37 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief check if the given int is an ascii character
 * 
 * @param c int to check
 * @return int boolean
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
