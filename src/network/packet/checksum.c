/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:02:51 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 00:06:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

t_uint16	ft_packet_checksum(char *data, t_size size)
{
	t_uint32	sum;
	t_size		i;

	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += ft_ntohs(*((t_uint16 *)(data + i)));
		if (sum >> 16)
			sum -= 0xffff;
		i += 2;
	}
	if (size & 1)
	{
		sum += ft_ntohs(*((t_uint16 *)(data + size - 1)));
		if (sum > 0xffff)
			sum -= 0xffff;
	}
	return (ft_htons(~sum));
}
