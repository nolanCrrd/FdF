/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:24:08 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 13:18:37 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief return the given char into lower case
 * 
 * @param c char to convert
 * @return int converted char
 */
int	ft_tolower(int c)
{
	return (c + ((c >= 'A' && c <= 'Z') * 32));
}
