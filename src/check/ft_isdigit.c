/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:31:21 by pix               #+#    #+#             */
/*   Updated: 2024/08/18 16:26:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief checks if c is a digit (0 through 9).
 *
 * @param c character value to check
 *
 * @return t_bool TRUE if character is a digit and FALSE if not
 */
t_bool	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}
