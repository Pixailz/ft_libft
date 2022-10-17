/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/10/17 09:45:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_integer.h"

/**
 * @brief			Converts the initial portion of the string pointed to by str
 *					to t_uint64, given a string base.
 *
 * @param nstr		String to convert
 * @param base		String base to convert from
 *
 * @return (t_uint64)	The converted value or 0 on error
 */
t_uint64	ft_atou_base(const char *nstr, const char *base)
{
	char		*nptr;
	t_uint64	to_dec;
	t_size		base_len;

	to_dec = 0;
	nptr = (char *)nstr;
	base_len = ft_strlen((char *)base);
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			return (-1);
	while (ft_get_base(*nptr, base) != -1)
		to_dec = (to_dec * base_len) + ft_get_base(*nptr++, base);
	return (to_dec);
}
