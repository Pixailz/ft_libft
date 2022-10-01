/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgoodu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:15:28 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/01 18:38:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

t_bool	ft_isgoodu(t_uint32 n, int is_last)
{
	t_bool			is_good;
	static t_uint32	last_value = 0;

	is_good = True;
	if (n > UINT_MAX)
		is_good = False;
	if (last_value)
		if (last_value > n)
			is_good = False;
	if (is_last)
		last_value = 0;
	else
		last_value = n;
	return (is_good);
}
