/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:54:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 22:51:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

void	ft_pkt_icmp_checksum(t_icmphdr_echo *packet, t_size size)
{
	packet->checksum = 0;
	packet->checksum = ft_pkt_checksum((void *)packet, size);
}
