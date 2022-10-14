/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:48:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 05:15:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if c is a white-space characters. these are:
 * 					space, form-feed ('\f'), newline ('\n'),
 * 					carriage return ('\r'), horizontal-tab ('\t') or vertical
 * 					tab ('\v')
 *
 * @param c			Character value to check
 *
 * @return (t_bool)	TRUE if character is a space character and FALSE if not
 */
t_bool	ft_isspace(const char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
