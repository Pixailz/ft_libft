/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:30:06 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:50:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

char	*ft_memchr(char *buf, unsigned char c, t_size n)
{
	if (!buf)
		return (NULL);
	while (*buf && *buf != c && n--)
		buf++;
	if (!*buf)
		return (NULL);
	return (++buf);
}
