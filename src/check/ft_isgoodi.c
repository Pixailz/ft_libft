/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgoodi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:06:36 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 18:39:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

t_bool	ft_isgoodi(int n, int neg)
{
	t_bool	is_good;

	is_good = True;
	if (neg == 1)
	{
		if (n > INT_MAX || n < 0)
			is_good = False;
	}
	else
	{
		if ((n * neg) < INT_MIN || (n * neg) > 0)
			is_good = False;
	}
	return (is_good);
}
