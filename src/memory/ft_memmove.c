/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:58:06 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

/**
 * @brief			Copies n bytes from memory area src to memory area dest. The
 *					memory areas may overlap: copying takes place as though the
 *					bytes in src are first copied into a temporary array that
 *					does not overlap src or dest, and the bytes are then copied
 *					from the temporary array to dest.
 *
 * @param dest		Destination memory area
 * @param src		Source memory area
 * @param n			Number of bytes to copy
 *
 * @return (void *)	The ft_memmove() function returns a pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, t_size n)
{
	t_uint8	*tdst;
	t_uint8	*tsrc;

	if (!dest && !src)
		return (dest);
	tdst = (t_uint8 *)dest;
	tsrc = (t_uint8 *)src;
	if (tdst > tsrc)
	{
		tsrc += (n - 1);
		tdst += (n - 1);
		while (n--)
			*tdst-- = *tsrc--;
	}
	else
		while (n--)
			*tdst++ = *tsrc++;
	return (dest);
}
