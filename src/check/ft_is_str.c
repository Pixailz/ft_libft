/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:43:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/09 03:04:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

t_bool	ft_is_str(const char *str, t_bool func(char))
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
		if (!func(*ptr++))
			return (FALSE);
	return (TRUE);
}
