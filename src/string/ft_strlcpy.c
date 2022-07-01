/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:07:10 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Copy strings. copies up to size - 1 characters from the
 *					NULL-terminated string src to dst, NUL-terminating the
 *					result.
 *
 * @param dest		String to copy on
 * @param src		String to copy from
 * @param size		Full size of dest
 *
 * @return (t_uint32)The ft_strlcat() function return the total length of the
 *					string he tried to create. that means the length of src.
 */
t_uint32	ft_strlcpy(char *dest, char *src, t_size size)
{
	char			*tmp;
	t_uint32		i;

	tmp = src;
	while (*tmp)
		tmp++;
	i = tmp - src;
	if (!size)
		return (i);
	tmp = dest;
	while (--size && *src)
		*dest++ = *src++;
	*dest = 0;
	return (i);
}
