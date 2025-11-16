/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:24:10 by ncorrear          #+#    #+#             */
/*   Updated: 2025/11/14 13:18:37 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Return the upper char of the given char
 * 
 * @param c char to upper
 * @return int converted char
 */
int	ft_toupper(int c)
{
	return (c - ((c >= 'a' && c <= 'z') * 32));
}
