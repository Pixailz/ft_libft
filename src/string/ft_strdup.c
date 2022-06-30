/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:30:46 by pix               #+#    #+#             */
/*   Updated: 2022/06/30 21:46:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stdlib.h>

/**
 * @brief			Returns a pointer to a new string which is a duplicate of
 *					the string s.
 *
 * @param src		String to copy
 *
 * @return (char *)	On success, returns a pointer to the duplicated string.
 */
char	*ft_strdup(char *src)
{
	char	*tmp;
	char	*ptr;

	tmp = src;
	while (*tmp)
		tmp++;
	ptr = (char *)malloc((tmp - src) + 1);
	tmp = ptr;
	while (*src && tmp)
		*tmp++ = *src++;
	if (ptr)
		*tmp = 0;
	return (ptr);
}
