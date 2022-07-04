/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 01:11:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

static int	ft_get_base(int c, const char *base)
{
	int	counter;

	counter = 0;
	while (base[counter])
	{
		if (c == base[counter])
			return (counter);
		counter++;
	}
	return (-1);
}

/**
 * @brief			Converts the initial portion of the string pointed to by str
 *					to int, given a string base.
 *
 * @param nstr		String to convert
 * @param base		String base to convert from
 *
 * @return (int)	The converted value or 0 on error
 */
int	ft_atoi_base(char *nstr, const char *base)
{
	char		*nptr;
	long int	to_dec;
	int			neg;
	t_size		base_len;

	to_dec = 0;
	neg = 1;
	nptr = nstr;
	base_len = ft_strlen((char *)base);
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			neg = ~(neg - 1);
	while (ft_get_base(*nptr, base) != -1)
		to_dec = (to_dec * base_len) + ft_get_base(*nptr++, base);
	if (neg == -1 && to_dec < INT_MIN)
		return (0);
	else if (to_dec < INT_MIN)
		return (-1);
	return (to_dec * neg);
}
