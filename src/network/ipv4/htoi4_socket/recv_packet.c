/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:22:20 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 09:40:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

static t_uint32	check_reply(t_packet *pkt)
{
	t_udphdr	*pack_udp;
	t_uint16	src_port;
	t_uint16	dst_port;

	pack_udp = ft_pkt_get_udp(pkt);
	src_port = ft_htons(pack_udp->src_port);
	dst_port = ft_htons(pack_udp->dst_port);
	if (dst_port == DNS_SRC_PORT && src_port == DNS_DST_PORT)
	{
		return (1);
	}
	return (0);
}

static t_bool	recv_reply(int sock, t_packet *pong_pkt)
{
	long			ret;

	ret = recvfrom(
		sock,					// SOCKET
		pong_pkt->data,			// BUFFER
		PACK_MAX_LEN,			// LEN
		0,						// FLAG
		FT_NULL,				// SOCK ADDR FROM
		FT_NULL					// SOCK ADDR FROM LEN
	);
	return (ret == -1);
}

t_int4	ft_htoi4_recv_packet(int sock)
{
	t_packet	pkt;

	while (TRUE)
	{
		pkt = ft_pkt_get();
		if (recv_reply(sock, &pkt))
			return 0;
		if (check_reply(&pkt))
			break;
	}
	return (ft_dns_get_a_record(&pkt));
}
