/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:00:23 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

/**
 * @brief			Compares the first n bytes (each interpreted as unsigned
 *					char) of the memory areas s1 and s2.
 *
 * @param s1		Memory area to compare
 * @param s2		Memory area to compare
 * @param n			Number of inital bytes to analyse
 *
 * @return (int)	The ft_memcmp() function returns an integer less than, equal
 *					to, or greater than zero if the first n bytes of s1 is
 *					found, respectively, to be less than, to match, or be
 *					greater than the first n bytes of s2.
 *
 *					For a nonzero return value, the sign is determined by the
 *					sign of the difference between the first pair of bytes
 *					(interpreted as unsigned char) that differ in s1 and s2.
 *
 *					If n is zero, the return value is zero.
 */
int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	unsigned char	*ts1;
	unsigned char	*ts2;

	if (!n)
		return (0);
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while (--n && *ts1 == *ts2)
	{
		ts1++;
		ts2++;
	}
	return (*ts1 - *ts2);
}
