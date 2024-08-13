/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:03:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/12 16:39:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_packet	ft_htoi4_init_packet(char *domain)
{
	t_packet	pkt;
	t_iphdr		*pkt_ip;
	t_udphdr	*pkt_udp;
	t_dnshdr	*pkt_dns;

	pkt = ft_pkt_get();

	pkt_ip = ft_pkt_get_ip(&pkt);
	ft_pkt_fill_ip_default(pkt_ip);
	pkt_ip->identification = ft_htons(420);
	pkt_ip->fragment_off = ft_htons(ft_pkt_fragment_offset(IPHDR_F_DONT_FRAG, 0));
	pkt_ip->ttl = DNS_TTL;
	pkt_ip->protocol = IPPROTO_UDP;
	pkt_ip->dst_addr = get_dns_nameserver();
	pkt_udp = ft_pkt_get_udp(&pkt);
	pkt_udp->src_port = ft_htons(DNS_SRC_PORT);
	pkt_udp->dst_port = ft_htons(DNS_DST_PORT);
	pkt_dns = ft_pkt_get_dns(&pkt);
	pkt_dns->identification = ft_htons(421);
	pkt_dns->recursion_desired = 1;
	pkt_dns->question_count = ft_htons(1);
	ft_pkt_dnsq_fill_a(&pkt, domain, DNS_CLASS_IN);
	pkt_ip->total_len = ft_htons(PACK_LEN_IP + PACK_LEN_UDP + PACK_LEN_DNS + ft_pkt_dnsq_len(pkt));
	pkt_udp->length = ft_htons(PACK_LEN_UDP + PACK_LEN_DNS + ft_pkt_dnsq_len(pkt));
	return (pkt);
}
