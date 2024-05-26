/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_socket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:00:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:23:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

int	ft_htoi4_init_socket(void)
{
	int				sock;
	struct timeval	tv;

	sock = socket(PF_INET, SOCK_RAW, IPPROTO_UDP);
	if (sock == -1)
	{
		ft_perr("ft_htoi4_init_socket: Permission denied\n");
		return (sock);
	}
	tv.tv_usec = DNS_TIMEOUT % A_SEC;
	tv.tv_sec = DNS_TIMEOUT / A_SEC;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1)
	{
		ft_perr("ft_htoi4_init_socket: SO_RCVTIMEO\n");
		return (sock);
	}
	if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (int [1]){1}, \
															sizeof(int)) == -1)
	{
		ft_perr("ft_htoi4_init_socket: IP_HDRINCL\n");
		return (sock);
	}
	return (sock);
}
