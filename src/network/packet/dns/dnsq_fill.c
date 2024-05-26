/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dnsq_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:12:10 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

void	ft_pkt_dnsq_fill(
		t_packet *pack,
		char *domain,
		t_uint16 type,
		t_uint16 class
	)
{
	unsigned char	*dns_data;
	char			*fmt_domain;
	t_size			len_fmt_domain;

	dns_data = ft_pkt_get_dns_data(pack);
	fmt_domain = ft_dns_get_domain_fmt(domain);
	len_fmt_domain = ft_strlen(fmt_domain);
	ft_memcpy(dns_data, fmt_domain, len_fmt_domain);
	dns_data[len_fmt_domain] = 0;
	free(fmt_domain);
	dns_data[len_fmt_domain + 1] = (type & 0xff00) >> 8;
	dns_data[len_fmt_domain + 2] = type & 0x00ff;
	dns_data[len_fmt_domain + 3] = (class & 0xff00) >> 8;
	dns_data[len_fmt_domain + 4] = class & 0x00ff;
}
