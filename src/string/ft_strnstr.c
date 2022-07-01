/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:54:11 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

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
 *					occurs nowhere in str, FT_NULL is returned; otherwise a
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
	return (FT_NULL);
}
