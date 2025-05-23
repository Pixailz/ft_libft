/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:31:21 by pix               #+#    #+#             */
/*   Updated: 2025/04/18 13:55:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

/**
 * @brief Checks if c is an alphabetic character.
 *
 * @param c Character value to check
 *
 * @return t_bool TRUE if character is alphabetic and FALSE if not
 */
t_bool	ft_isalpha(const char c)
{
	return (ft_islower(c) || ft_isupper(c));
}
