/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:43:29 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/16 11:11:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief Check if all characters in a string are valid, given a function
 *
 * The function should take a character as argument and return a t_bool
 *
 * @param str The string to check
 * @param func The function to check the characters
 *
 * @return t_bool TRUE if all characters are valid, FALSE otherwise
 */
t_bool	ft_is_str(const char *str, t_bool func(char))
{
	const char	*ptr;

	ptr = (const char *)str;
	while (*ptr)
		if (!func(*ptr++))
			return (FALSE);
	return (TRUE);
}
