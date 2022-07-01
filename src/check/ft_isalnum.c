/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:39:55 by pix               #+#    #+#             */
/*   Updated: 2022/07/01 11:58:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief			Checks if c is an alphanumeric character. equivalent to
 *					(ft_isalpha(c) || ft_isdigit(c))
 *
 * @param c			Character value to check
 *
 * @return (int)	Nonzero if character is alphanumeric and zero if not
 */
int	ft_isalnum(const char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
