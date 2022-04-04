/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:21:15 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 03:04:24 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Copy n bytes of src to dest, don't check for the length of
 *					dest
 *
 * @param dest		Destination string
 * @param src		Source string
 * @param n			Size to copy
 *
 * @return (char *)	The copied string
 */
char	*ft_strncpy(char *dest, char *src, t_size n)
{
	char	*tmp;

	tmp = dest;
	n++;
	while (--n && *src)
		*tmp++ = *src++;
	while (n--)
		*tmp++ = 0;
	return (dest);
}
