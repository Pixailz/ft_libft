/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:06:28 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 02:58:41 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
