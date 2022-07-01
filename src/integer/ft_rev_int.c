/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:06:28 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:03:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

/**
 * @brief			Reverse an integer
 *
 * @param nb		Number to reverse
 *
 * @return (int)	Reversed integer
 */
int	ft_rev_int(int nb)
{
	int	r;

	r = 0;
	while (nb)
	{
		r *= 10;
		r += (nb % 10);
		nb /= 10;
	}
	return (r);
}
