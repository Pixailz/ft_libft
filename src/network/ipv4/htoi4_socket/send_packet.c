/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:18:13 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:23:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

int	ft_htoi4_send_packet(int socket, t_packet pkt)
{
	long			ret;
	struct sockaddr	dst;

	dst = ft_ltoaddr(DNS_ADDR);
	ret = sendto(
		socket,
		pkt.data,
		ft_pkt_dnsq_len(pkt) + PACK_LEN_IP + PACK_LEN_UDP + PACK_LEN_DNS,
		0,
		&dst,
		sizeof(dst)
	);
	ret = ret == -1;
	if (ret)
		ft_perr("ft_htoi4_send_packet: failed\n");
	return (ret);
}
