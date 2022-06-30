/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 16:13:18 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Converts the initial portion of the string pointed to by str
 *					to int.
 *
 * @param nptr		String to convert
 *
 * @return (int)	The converted value or 0 on error
 */
int	ft_atoi(char *nptr)
{
	long int	to_dec;
	int			neg;

	to_dec = 0;
	neg = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			neg = ~(neg - 1);
	while (*nptr >= '0' && *nptr <= '9')
		to_dec = (to_dec * 0xA) + (*nptr++ & 0xF);
	if (neg == -1 && to_dec < -2147483648)
		return (0);
	if (neg && to_dec < -2147483648)
		return (-1);
	return (to_dec * neg);
}
