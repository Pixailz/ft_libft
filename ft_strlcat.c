/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:33:00 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 18:36:46 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Concatenate strings. appends the NUL-terminated string src
 *					to the end of dst.
 *
 * @param dest		String to concatenate on
 * @param src		String to concatenate at the end of dst
 * @param size		Full size of dest
 *
 * @return (t_uint32)The ft_strlcat() function return the total length of the
 *					string he tried to create. that means the initial length of
 *					dst plus the length of src.
 */
t_uint32	ft_strlcat(char *dest, char *src, t_size size)
{
	t_uint32		n;
	t_uint32		dl;
	char			*d;
	char			*s;

	d = dest;
	s = src;
	n = size;
	while (n-- && *d)
		d++;
	dl = d - dest;
	n = size - dl;
	if (!n)
		return (dl + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return (dl + (s - src));
}
