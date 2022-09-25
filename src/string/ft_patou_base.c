/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patou_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:34:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/25 04:15:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static t_uint32	ft_atou_base_p(char *nstr, const char *base, int *has_overflow)
{
	char		*nptr;
	t_uint32	to_dec;
	t_size		base_len;

	to_dec = 0;
	nptr = nstr;
	base_len = ft_strlen((char *)base);
	*has_overflow = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			*has_overflow = 1;
	while (ft_get_base(*nptr, base) != -1 && !*has_overflow)
	{
		if (!ft_isgoodu(to_dec, 0))
			*has_overflow = 1;
		to_dec = (to_dec * base_len) + ft_get_base(*nptr++, base);
	}
	if (!ft_isgoodu(to_dec, 1))
		*has_overflow = 1;
	return (to_dec);
}

t_uint32	ft_patou_base(char *nstr, const char *base, int *has_overflow)
{
	t_uint32	to_dec;

	to_dec = 0;
	if (has_overflow == FT_NULL)
		to_dec = ft_atou_base(nstr, base);
	else
		to_dec = ft_atou_base_p(nstr, base, has_overflow);
	return (to_dec);
}
