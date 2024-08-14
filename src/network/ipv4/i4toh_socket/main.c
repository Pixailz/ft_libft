/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:56:34 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 16:40:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

char	*ft_i4toh_socket(t_int4 ip)
{
	static int	sock = -2;
	t_packet	pkt;
	char		**names;
	char		*name;

	if (sock == -2)
		sock = ft_i4toh_init_socket();
	if (sock == -1)
		return (0);

	pkt = ft_i4toh_init_packet(ip);

	if (ft_i4toh_send_packet(sock, pkt))
		return (0);
	names = ft_i4toh_recv_packet(sock);
	name = FT_NULL;
	if (names && names[0])
	{
		name = ft_strdup(names[0]);
		ft_free_char_pp(names);
	}
	return (name);
}

char	**ft_i4tohs_socket(t_int4 ip)
{
	static int	sock = -2;
	t_packet	pkt;
	char		**names;

	if (sock == -2)
		sock = ft_i4toh_init_socket();
	if (sock == -1)
		return (0);

	pkt = ft_i4toh_init_packet(ip);

	if (ft_i4toh_send_packet(sock, pkt))
		return (0);
	names = ft_i4toh_recv_packet(sock);
	return (names);
}
