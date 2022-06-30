/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:47:57 by pix               #+#    #+#             */
/*   Updated: 2022/04/04 02:55:07 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Checks if c is any printable character including space.
 *
 * @param c			Character value to check
 *
 * @return (int)	Nonzero if character is printable and zero if not
 */
int	ft_isprint(int c)
{
	return (c >= ' ' && c < 0x7F);
}
