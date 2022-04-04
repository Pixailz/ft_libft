/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:08:31 by stales            #+#    #+#             */
/*   Updated: 2022/04/04 03:07:02 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Removes all character from set from the beginning and the
 *					end of a string.
 *
 * @param s1		String to trim
 * @param set		Set to remove
 *
 * @return (char *)	The trimed strings
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	t_size	s;
	t_size	i;

	if (!s1 || !set)
		return (LIBFT_NULL);
	i = 0;
	s = ft_strlen((char *)s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[s - 1] && ft_strchr(set, s1[s - 1]) && s > i)
		s--;
	return (ft_substr(s1, i, s - i));
}
