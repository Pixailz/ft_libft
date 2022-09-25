/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/09/25 01:07:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

/**
 * @brief			Converts the initial portion of the string pointed to by str
 *					to t_int64, given a string base.
 *
 * @param nstr		String to convert
 * @param base		String base to convert from
 *
 * @return (t_int64)	The converted value or 0 on error
 */
t_int64	ft_atoll_base(char *nstr, const char *base)
{
	char		*nptr;
	t_int64		to_dec;
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
	if (neg == -1 && to_dec < LLONG_MIN)
		return (0);
	else if (to_dec < LLONG_MIN)
		return (-1);
	return (to_dec * neg);
}
