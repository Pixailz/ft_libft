/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:17:18 by pix               #+#    #+#             */
/*   Updated: 2022/07/05 01:00:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

/**
 * @brief			Length of an integer, given a base.
 *
 * @param void_nbr	Integer to take the size of.
 * @param base		String base to convert from
 *
 * @return (t_size)	The length of nb, if number is negative, add +1 for the '-'.
 */
t_size	ft_nbrlen_base(const void *void_nbr, const char *base)
{
	t_size	size;
	t_size	size_base;
	t_int64	nb;

	size = 0;
	size_base = ft_strlen((char *)base);
	nb = (t_int64)void_nbr;
	if (nb < 0)
	{
		nb = ~(nb - 1);
		size++;
	}
	while (nb && ++size)
		nb /= size_base;
	return (size);
}
