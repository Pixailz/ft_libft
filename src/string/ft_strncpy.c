/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:21:15 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

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
