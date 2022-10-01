/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgoodll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:08:36 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 18:38:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

t_bool	ft_isgoodll(t_int64 n, int neg)
{
	t_bool	is_good;

	is_good = True;
	if (neg == 1)
	{
		if (n > LLONG_MAX || n < 0)
			is_good = False;
	}
	else
	{
		if ((n * neg) < LLONG_MIN || (n * neg) > 0)
			is_good = False;
	}
	return (is_good);
}
