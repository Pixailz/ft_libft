/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:22:20 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 15:46:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

static t_uint32	check_reply(t_packet *pkt)
{
	t_udphdr	*pack_udp;
	t_dnshdr	*pack_dns;
	t_uint16	src_port;
	t_uint16	dst_port;

	pack_udp = ft_pkt_get_udp(pkt);
	pack_dns = ft_pkt_get_dns(pkt);
	src_port = ft_htons(pack_udp->src_port);
	dst_port = ft_htons(pack_udp->dst_port);
	if (dst_port != DNS_SRC_PORT || src_port != DNS_DST_PORT)
		return (1);
	if (pack_dns->response_code != DNS_RCODE_NO_ERROR)
		return (2);
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
		0						// SOCK ADDR FROM LEN
	);
	return (ret == -1);
}

char	**ft_i4toh_recv_packet(int sock)
{
	t_packet	pkt;
	t_uint32	retv;

	while (TRUE)
	{
		pkt = ft_pkt_get();
		if (recv_reply(sock, &pkt))
		{
			return FT_NULL;
		}
		retv = check_reply(&pkt);
		if (!retv)
			break;
		else if (retv == 2)
			return FT_NULL;
	}
	return (ft_dns_get_record_ptr(&pkt));
}
