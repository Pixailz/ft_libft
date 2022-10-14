/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:47:57 by pix               #+#    #+#             */
/*   Updated: 2022/10/14 05:27:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if c is any printable character including space.
 *
 * @param c			Character value to check
 *
 * @return (t_bool)	TRUE if character is printable and FALSE if not
 */
t_bool	ft_isprint(const char c)
{
	return (c >= ' ' && c < 0x7F);
}
