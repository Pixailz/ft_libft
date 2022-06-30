/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:56:04 by pix               #+#    #+#             */
/*   Updated: 2022/06/30 21:46:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/**
 * @brief			Calculate the length of a string
 *
 * @param str		String to mesure
 *
 * @return (int)	Length of the strings
 */
int	ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
		str++;
	return (str - tmp);
}
