/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_endianness.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:53:42 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 13:57:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

/**
 * @brief Get the endianness of the system
 *
 * @return t_bool TRUE if the system is big endian, FALSE if the system is little endian
 */
t_bool	ft_get_endianness(void)
{
	int	a;

	a = 1;
	return (((char *)&a)[0] != 1);
}
