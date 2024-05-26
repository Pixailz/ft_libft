/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:56:34 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 02:07:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_int4	ft_htoi4_socket(char *domain)
{
	t_int4		ip;
	int			sock;
	t_packet	pkt;

	sock = ft_htoi4_init_socket();
	if (sock == -1)
		return (0);

	pkt = ft_htoi4_init_packet(domain);

	if (ft_htoi4_send_packet(sock, pkt))
		return (0);
	ip = ft_htoi4_recv_packet(sock);
	if (sock != -1)
		close(sock);
	return (ip);
}
