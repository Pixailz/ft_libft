/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:43:03 by pix               #+#    #+#             */
/*   Updated: 2022/04/04 02:54:44 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Checks if c fit in the ascii table.
 *
 * @param c			Character value to check
 *
 * @return (int)	Nonzero if character is in the ascii table and zero if not
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 0x7F);
}
