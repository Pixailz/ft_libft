/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:32:38 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

/**
 * @brief			Copies n bytes from memory area src to memory area dest.
 *					The memory areas must not overlap.
 *
 * @param dest		Destination memory area
 * @param src		Source memory area
 * @param n			Number of bytes to copy
 *
 * @return (void *)	The ft_memcpy() function returns a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, t_size n)
{
	unsigned char	*tdst;
	unsigned char	*tsrc;

	if (!dest && !src)
		return (dest);
	tsrc = (unsigned char *)src;
	tdst = (unsigned char *)dest;
	while (n--)
		*tdst++ = *tsrc++;
	return (dest);
}
