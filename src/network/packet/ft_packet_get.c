/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_packet_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:26:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 22:54:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

t_packet	ft_packet_get(void)
{
	t_packet	packet;

	ft_bzero(&packet, sizeof(t_packet));
	return (packet);
}

t_iphdr	*ft_packet_get_ip(t_packet *packet)
{
	return ((t_iphdr *)packet->data);
}

t_icmphdr_echo	*ft_packet_get_icmp_echo(t_packet *packet)
{
	return ((t_icmphdr_echo *)(packet->data + PACK_LEN_IP));
}
