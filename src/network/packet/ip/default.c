/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:54:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 22:40:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

void	ft_pkt_fill_ip_default(t_iphdr *packet)
{
	packet->version = 4;
	packet->ihl = PACK_LEN_IP / 4;
}
