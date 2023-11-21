/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:26:34 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 18:49:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/ipv4.h"

t_uint16	ft_htons(t_uint16 h)
{
	t_uint16	n;

	n = (h & 0xff00) >> 8;
	n |= (h & 0x00ff) << 8;
	return (n);
}