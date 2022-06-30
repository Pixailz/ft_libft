/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:39:55 by pix               #+#    #+#             */
/*   Updated: 2022/04/04 02:53:00 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Checks if c is an alphanumeric character. equivalent to
 *					(ft_isalpha(c) || ft_isdigit(c))
 *
 * @param c			Character value to check
 *
 * @return (int)	Nonzero if character is alphanumeric and zero if not
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
