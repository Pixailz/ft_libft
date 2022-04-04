/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:41:43 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 03:08:04 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Compares the first (at most) n bytes of the two strings s1
 *					and s2.
 *
 * @param s1		First string
 * @param s2		Second string
 * @param n			Size to compare
 *
 * @return (int)	Return an integer less than, equal to, or greater than zero
 *					if the first n bytes of s1 is found, respectively, to be
 *					less than, to match, or be greater than s2.
 */
int	ft_strncmp(char *s1, char *s2, t_size n)
{
	if (!n)
		return (0);
	while (*s1 && *s2 && --n && *s1++ == *s2)
		s2++;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
