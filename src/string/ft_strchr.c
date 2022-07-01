/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:45:00 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Returns a pointer to the first occurence of the character c
 *					in the string s
 *
 * @param s			String to search on
 * @param c			Character to search for
 *
 * @return (int)	Return a pointer to the matched character or NULL if the
 *					character is not found. The terminating null byte is
 *					considered part of the string, so that if c is specified as
 *					'\0', these functions return a pointer to the terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp && *tmp != (char)c)
		tmp++;
	if (*tmp == c)
		return (tmp);
	return (FT_NULL);
}
