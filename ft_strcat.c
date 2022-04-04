/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:12:43 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 03:00:11 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Appends the src string to the dest string, overwriting the
 *					terminating null byte ('\0') at the end of dest, and then
 *					adds a terminating null byte.
 *
 * @param dest		Base string
 * @param src		Suffix string
 *
 * @return (char*)	The joined list
 */
char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (dest);
}
