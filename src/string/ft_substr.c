/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:18:24 by stales            #+#    #+#             */
/*   Updated: 2022/07/01 12:04:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Return a portion of s, begin at start for size of len
 *
 * @param s			String to cut
 * @param start		Start of the cut
 * @param len		Length of the cut
 *
 * @return (char *)	The cutted string
 */
char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char		*str;
	t_size		i;

	str = (char *)malloc(len + 1);
	if (!str || !s)
		return (FT_NULL);
	if ((int)start > ft_strlen((char *)s))
		return (ft_strdup(""));
	i = 0;
	while (i < len)
	{
		str[i] = *(s + start + i);
		i++;
	}
	str[i] = 0;
	return (str);
}
