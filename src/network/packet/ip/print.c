/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:20:12 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 23:47:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

# if FT_PING_USE_IP_OPTS == 1
void	ft_pkt_print_ip(int fd, t_iphdr *pkt)
{
	ft_dprintf(fd, FMT_IPHDR, \
		pkt->version, pkt->ihl, pkt->tos, pkt->total_len, \
		pkt->identification, \
		(pkt->fragment_off & IPHDR_M_FLAGS) >> 13, \
		pkt->fragment_off & IPHDR_M_FRAG_OFF, \
		pkt->ttl, pkt->protocol, pkt->checksum, \
		pkt->src_addr, \
		pkt->dst_addr, \
		pkt->options, pkt->padding);
}
# else
void	ft_pkt_print_ip(int fd, t_iphdr *pkt)
{
	ft_dprintf(fd, FMT_IPHDR, \
		pkt->version, pkt->ihl, pkt->tos, pkt->total_len, \
		pkt->identification, \
		(pkt->fragment_off & IPHDR_M_FLAGS) >> 13, \
		pkt->fragment_off & IPHDR_M_FRAG_OFF, \
		pkt->ttl, pkt->protocol, pkt->checksum, \
		pkt->src_addr, \
		pkt->dst_addr);
}
# endif // FT_PING_USE_IP_OPTS == 1
