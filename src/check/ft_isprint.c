/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:47:57 by pix               #+#    #+#             */
/*   Updated: 2022/07/01 11:49:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if c is any printable character including space.
 *
 * @param c			Character value to check
 *
 * @return (int)	Nonzero if character is printable and zero if not
 */
int	ft_isprint(const char c)
{
	return (c >= ' ' && c < 0x7F);
}
