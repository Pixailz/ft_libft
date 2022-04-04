/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:54:11 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 03:05:27 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Locates the first occurrence of the null-terminated
 *					string to_find in the null-terminated string str, where not
 *					more than len characters are searched.
 *
 * @param str		The "haystack"
 * @param to_find	The "needle"
 * @param n			Size to search
 *
 * @return  (char *)If to_find is an empty string, str is returned; if to_find
 *					occurs nowhere in str, LIBFT_NULL is returned; otherwise a
 *					pointer to the first character of the first occurrence of
 *					to_find is returned.
 */
char	*ft_strnstr(char *str, char *to_find, int n)
{
	char	*tmp;
	char	*ttmp;
	char	*sstr;

	if (!*to_find)
		return (str);
	ttmp = str;
	while (to_find && *str && (str - ttmp) < n--)
	{
		if (*str == *to_find)
		{
			tmp = to_find;
			sstr = str;
			while (*sstr && *tmp && *sstr++ == *tmp)
				tmp++;
			if (*tmp == 0)
				return (str);
		}
		str++;
	}
	return (LIBFT_NULL);
}
