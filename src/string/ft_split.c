/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:01:09 by stales            #+#    #+#             */
/*   Updated: 2022/07/06 15:33:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Split string s with c as separator
 *
 * @param c			Character as separator
 * @param s			String to return
 *
 * @return (char **)Allocated list of separated string, termined by NULL char
 */
static char	*ft_init_str(char *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

char	**ft_split(char *s, char c)
{
	int		i[2];
	char	**ptr;

	if (!s)
		return (NULL);
	i[1] = ft_get_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (i[1] + 1));
	i[0] = -1;
	while (ptr && ++i[0] < i[1])
	{
		while (s[0] == c)
			s++;
		ptr[i[0]] = ft_init_str(s, c);
		if (!ptr[i[0]])
		{
			while (i[0] > 0)
				free(ptr[i[0]--]);
			free(ptr);
			return (NULL);
		}
		s = s + ft_strlen(ptr[i[0]]);
	}
	if (ptr)
		ptr[i[0]] = 0;
	return (ptr);
}
