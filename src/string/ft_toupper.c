/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:59:57 by pix               #+#    #+#             */
/*   Updated: 2022/06/30 21:46:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/**
 * @brief			Converts the letter c to upper case, if possible.
 *
 * @param c			Character to convert
 *
 * @return (int)	The value returned is that of the converted letter, or c if
 *					the conversion was not possible.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c ^ 0x20);
	return (c);
}
