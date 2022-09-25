/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:34:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 01:10:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static t_int64	ft_atoll_protected(char *nstr, int *has_overflow)
{
	char	*nptr;
	t_int64	to_dec;
	int		neg;

	to_dec = 0;
	neg = 1;
	nptr = nstr;
	*has_overflow = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			neg = ~(neg - 1);
	while (*nptr >= '0' && *nptr <= '9' && !*has_overflow)
	{
		if (!ft_isgoodll(to_dec, neg))
			*has_overflow = 1;
		to_dec = (to_dec * 0xA) + (*nptr++ & 0xF);
	}
	if (!ft_isgoodll(to_dec, neg))
		*has_overflow = 1;
	return (to_dec * neg);
}

t_int64	ft_patoll(char *nstr, int *has_overflow)
{
	t_int64	to_dec;

	to_dec = 0;
	if (has_overflow == FT_NULL)
		to_dec = ft_atoll(nstr);
	else
		to_dec = ft_atoll_protected(nstr, has_overflow);
	return (to_dec);
}
