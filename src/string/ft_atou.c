/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/10/17 09:44:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

/**
 * @brief			Converts the initial portion of the string pointed to by str
 *					to t_int64.
 *
 * @param nstr	String to convert
 *
 * @return (t_uint64)	The converted value or 0 on error
 */
t_uint64	ft_atou(const char *nstr)
{
	char		*nptr;
	t_uint64	to_dec;

	to_dec = 0;
	nptr = (char *)nstr;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			return (-1);
	while (*nptr >= '0' && *nptr <= '9')
		to_dec = (to_dec * 10) + (*nptr++ & 0xF);
	return (to_dec);
}
