/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoi_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:34:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 09:33:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief				Try to convert a nstr to integer
 *
 * @param nstr			string to convert
 * @param base			sting form base
 * @param has_flow	variable to for over|under flow
 *
 * @return (int)		set has_flow to 1 if overflow, 2 if underflow
 * 						otherwise return number
 * @note				if error occur, return value is not reliable
 */
static int	ft_atoi_base_p(const char *nstr, const char *base, int *has_flow)
{
	char	*nptr;
	int		to_dec;
	int		neg;
	t_size	base_len;

	to_dec = 0;
	neg = 1;
	nptr = (char *)nstr;
	base_len = ft_strlen((char *)base);
	*has_flow = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			neg = ~(neg - 1);
	while (ft_get_base(*nptr, base) != -1 && !*has_flow)
	{
		if (!ft_isgoodi(to_dec, neg))
			*has_flow = 1;
		to_dec = (to_dec * base_len) + ft_get_base(*nptr++, base);
	}
	if (!ft_isgoodi(to_dec, neg))
		*has_flow = 1;
	return (to_dec * neg);
}

int	ft_patoi_base(const char *nstr, const char *base, int *has_flow)
{
	int	to_dec;

	to_dec = 0;
	if (has_flow == FT_NULL)
		to_dec = ft_atoi_base(nstr, base);
	else
		to_dec = ft_atoi_base_p(nstr, base, has_flow);
	return (to_dec);
}
