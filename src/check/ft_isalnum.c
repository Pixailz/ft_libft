/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:39:55 by pix               #+#    #+#             */
/*   Updated: 2024/08/14 22:40:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief Check if c is an alphanumeric character
 *
 * equivalent to (ft_isalpha(c) || ft_isdigit(c))
 *
 * @param c Character value to check
 *
 * @return t_bool TRUE if character is alphanumeric and FALSE if not
 */
t_bool	ft_isalnum(const char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
