/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:56:34 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 20:50:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_int4	ft_htoi4_socket(char *domain)
{
	t_int4				ip;
	static int			sock = -2;
	t_packet			pkt;

	if (sock == -2)
		sock = ft_htoi4_init_socket();
	if (sock == -1)
		return (0);
	pkt = ft_htoi4_init_packet(domain);
	if (ft_htoi4_send_packet(sock, pkt))
		return (0);
	ip = ft_htoi4_recv_packet(sock);
	return (ip);
}
