/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:06:54 by pix               #+#    #+#             */
/*   Updated: 2022/06/30 21:46:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/**
 * @brief			Converts the letter c to lower case, if possible.
 *
 * @param c			Character to convert
 *
 * @return (int)	The value returned is that of the converted letter, or c if
 *					the conversion was not possible.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c ^ 0x20);
	return (c);
}
