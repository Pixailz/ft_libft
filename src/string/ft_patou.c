/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:34:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 04:16:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static t_uint32	ft_atou_protected(char *nstr, int *has_overflow)
{
	char		*nptr;
	t_uint32	to_dec;

	to_dec = 0;
	nptr = nstr;
	*has_overflow = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			*has_overflow = 1;
	while (*nptr >= '0' && *nptr <= '9' && !*has_overflow)
	{
		if (!ft_isgoodu(to_dec, 0))
			*has_overflow = 1;
		to_dec = (to_dec * 10) + (*nptr++ & 0xF);
	}
	if (!ft_isgoodu(to_dec, 1))
		*has_overflow = 1;
	return (to_dec);
}

t_uint32	ft_patou(char *nstr, int *has_overflow)
{
	t_uint32	to_dec;

	to_dec = 0;
	if (has_overflow == FT_NULL)
		to_dec = ft_atou(nstr);
	else
		to_dec = ft_atou_protected(nstr, has_overflow);
	return (to_dec);
}
