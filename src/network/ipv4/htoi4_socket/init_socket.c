/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_socket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:00:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:23:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

int	ft_htoi4_init_socket(void)
{
	int	sock;

	sock = ft_socket(PF_INET, SOCK_RAW, IPPROTO_UDP);
	if (sock == -1)
	{
		ft_perr("ft_htoi4_init_socket: Permission denied\n");
		return (sock);
	}
	if (ft_setsockopt_timeout(sock, DNS_TIMEOUT))
	{
		ft_perr("ft_htoi4_init_socket: SO_RCVTIMEO\n");
		return (sock);
	}
	if (ft_setsockopt_ipheader(sock))
	{
		ft_perr("ft_htoi4_init_socket: IP_HDRINCL\n");
		return (sock);
	}
	return (sock);
}
