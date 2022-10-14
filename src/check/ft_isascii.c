/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:43:03 by pix               #+#    #+#             */
/*   Updated: 2022/10/14 05:08:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if c fit in the ascii table.
 *
 * @param c			Character value to check
 *
 * @return (t_bool)	TRUE if character is in the ascii table and FALSE if not
 */
t_bool	ft_isascii(const char c)
{
	int	tmp_c;

	tmp_c = (int)c;
	return (tmp_c >= 0 && tmp_c <= 0x7F);
}
