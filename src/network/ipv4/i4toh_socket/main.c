/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:56:34 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/27 12:33:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

char	*ft_i4toh_socket(t_int4 ip)
{
	int			sock;
	t_packet	pkt;
	char		*name;

	sock = ft_i4toh_init_socket();
	if (sock == -1)
		return (0);

	pkt = ft_i4toh_init_packet(ip);

	// ft_pkt_print_raw(1, (char *)pkt.data, PACK_LEN_IP + PACK_LEN_UDP + PACK_LEN_DNS + ft_pkt_dnsq_len(pkt));
	if (ft_i4toh_send_packet(sock, pkt))
		return (0);
	name = ft_i4toh_recv_packet(sock);

	if (sock != -1)
		close(sock);
	return (name);
}
