/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgoodll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:08:36 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 08:52:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if n is a good number according to climits.h
 *
 * @param n			number to check
 * @param neg		is negative
 *
 * @return (int)	zero if n is a good number and, 1 if overflow,
 * 					2 if underflow
 */
int	ft_isgoodll(t_int64 n, int neg)
{
	int	is_good;

	is_good = 0;
	if (neg == 1)
	{
		if (n > LLONG_MAX || n < 0)
			is_good = 1;
	}
	else
	{
		if ((n * neg) < LLONG_MIN || (n * neg) > 0)
			is_good = 2;
	}
	return (is_good);
}
