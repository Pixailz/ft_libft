/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:26:34 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 13:57:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_uint16	ft_htons(t_uint16 h)
{
	t_uint16	n;

	if (ft_get_endianness())
		return (h);
	n = (h & 0xff00) >> 8;
	n |= (h & 0x00ff) << 8;
	return (n);
}
