/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:51:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 05:15:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if c is a either a space (' ') or a
 * 					vertical tab ('\t')
 *
 * @param c			Character value to check
 *
 * @return (t_bool)	TRUE if character is blank and FALSE if not
 */
t_bool	ft_isblank(const char c)
{
	return (c == ' ' || c == '\t');
}
