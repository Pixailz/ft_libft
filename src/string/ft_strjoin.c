/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:58:41 by stales            #+#    #+#             */
/*   Updated: 2022/06/30 21:46:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stdlib.h>

/**
 * @brief			Concatenate two strings
 *
 * @param s1		Prefix string
 * @param s2		Suffix string
 *
 * @return (char *)	Allocated and joined string
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	t_size	size;
	char	*ptr;

	if (!s1 || !s2)
		return (LIBFT_NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	ptr = ft_calloc(0b1, size + 0b1);
	if (!ptr)
		return (LIBFT_NULL);
	ptr[size] = 0;
	ft_strcpy(ptr, (char *)s1);
	ft_strcat(ptr, (char *)s2);
	return (ptr);
}
