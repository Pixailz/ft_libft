/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:26:32 by stales            #+#    #+#             */
/*   Updated: 2022/07/05 01:29:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

/**
 * @brief			Scans the initial n bytes of the memory area pointed to by s
 *					for the first instance of c.
 *
 * @param s			Memory area to search from
 * @param c			Character to search for
 * @param n			Number of inital bytes to analyse
 *
 * @return (void *)	The ft_memchr() functions return a pointer to the matching
 *					byte or NULL if the character does not occur in the given
 *					memory area.
 */
void	*ft_memnchr(const void *s, int c, t_size n)
{
	t_uint8	*tmp;

	tmp = (t_uint8 *)s;
	while (--n)
	{
		if (*tmp == (t_uint8)c)
			return (tmp);
		tmp++;
	}
	return (FT_NULL);
}
