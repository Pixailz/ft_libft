/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:03:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

/**
 * @brief			Converts the initial portion of the string pointed to by str
 *					to int.
 *
 * @param nstr		String to convert
 *
 * @return (int)	The converted value or 0 on error
 */
int	ft_atoi(char *nstr)
{
	char	*nptr;
	t_int64	to_dec;
	int		neg;

	to_dec = 0;
	neg = 1;
	nptr = nstr;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			neg = ~(neg - 1);
	while (*nptr >= '0' && *nptr <= '9')
		to_dec = (to_dec * 0xA) + (*nptr++ & 0xF);
	if (neg == -1 && to_dec < INT_MIN)
		return (0);
	else if (to_dec < INT_MIN)
		return (-1);
	return (to_dec * neg);
}
