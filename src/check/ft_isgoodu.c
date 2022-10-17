/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgoodu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:15:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 08:54:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if n is a good number according to climits.h
 *
 * @param n			number to check
 * @param is_last	reset the static or not
 *
 * @return (t_bool)	TRUE if n is a good number and FALSE if not
 */
t_bool	ft_isgoodu(t_uint32 n, int is_last)
{
	t_bool			is_good;
	static t_uint32	last_value = 0;

	is_good = TRUE;
	if (n > UINT_MAX)
		is_good = FALSE;
	if (last_value)
		if (last_value > n)
			is_good = FALSE;
	if (is_last)
		last_value = 0;
	else
		last_value = n;
	return (is_good);
}
