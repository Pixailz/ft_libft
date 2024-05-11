/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:20:12 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 22:46:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

void	ft_pkt_print_udp(int fd, t_udphdr *pkt)
{
	ft_dprintf(fd, FMT_UDPHDR,
		pkt->src_port, pkt->dst_port,
		pkt->length, pkt->checksum
	);
}
