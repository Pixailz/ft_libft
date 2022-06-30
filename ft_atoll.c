/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:24:34 by stales            #+#    #+#             */
/*   Updated: 2022/06/30 19:59:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Converts the initial portion of the string pointed to by str
 *					to int.
 *
 * @param nbr_str	String to convert
 *
 * @return (long long)	The converted value or 0 on error
 */
long long	ft_atol(char *nbr_str)
{
	long long	to_dec;
	long long	neg;

	to_dec = 0;
	neg = 1;
	while (*nbr_str == ' ' || (*nbr_str >= '\t' && *nbr_str <= '\r'))
		nbr_str++;
	if ((*nbr_str == '+' || *nbr_str == '-'))
		if (*nbr_str++ == '-')
			neg = ~(neg - 1);
	while (*nbr_str >= '0' && *nbr_str <= '9')
		to_dec = (to_dec * 10) + (*nbr_str++ & 0xF);
	if (neg == -1 && to_dec < -2147483648)
		return (0);
	else if (to_dec < -2147483648)
		return (-1);
	return (to_dec * neg);
}
