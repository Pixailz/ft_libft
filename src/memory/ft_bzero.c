/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:52:28 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

/**
 * @brief			Erases the data in the n bytes of the memory starting at the
 *					location pointed to by s, by writing zeros (bytes containing
 *					'\0') to that area.
 *
 * @param s			Area to reset
 * @param n			Number of byte to reset
 *
 * @return (void)	None.
 */
void	ft_bzero(void *s, t_size n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
		*tmp++ = 0;
}
