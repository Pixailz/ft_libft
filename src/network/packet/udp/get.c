/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pkt_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:26:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 22:54:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

t_udphdr	*ft_pkt_get_udp(t_packet *packet)
{
	return ((t_udphdr *)(packet->data + PACK_LEN_IP));
}
