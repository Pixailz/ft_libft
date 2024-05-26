/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_record.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:32:26 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:57:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_int4	ft_htoi4_get_a_record(t_packet *pkt)
{
	t_dnshdr		*dns;
	unsigned char	*dns_data;
	t_dnsq			dnsq;
	t_dnsr			dnsr;
	int				i;
	t_int4			ip;

	ip = 0;
	dns = ft_pkt_get_dns(pkt);
	dns_data = ft_pkt_get_dns_data(pkt);
	i = ft_pkt_dnsq_get(dns_data, &dnsq);
	i += ft_pkt_dnsr_get(dns_data + i, ft_ntohs(dns->response_count), &dnsr);
	if (dnsr.type == DNS_TYPE_A)
		ip = ft_htonl(*(t_int4 *)dnsr.value);
	free(dnsq.name);
	free(dnsr.value);
	return (ip);
}
