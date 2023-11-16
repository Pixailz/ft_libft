/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntohs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:26:34 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 18:49:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/ipv4.h"

t_uint16	ft_ntohs(t_uint16 n)
{
	t_uint16	h;

	h = (n & 0xff00) >> 8;
	h |= (n & 0x00ff) << 8;
	return (h);
}
