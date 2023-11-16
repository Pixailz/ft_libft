/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htonl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:26:34 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 18:49:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/ipv4.h"

t_uint32	ft_htonl(t_uint32 h)
{
	t_uint32	n;

	n = (h & 0xff000000) >> 24;
	n |= (h & 0x00ff0000) >> 8;
	n |= (h & 0x0000ff00) << 8;
	n |= (h & 0x000000ff) << 24;
	return (n);
}
