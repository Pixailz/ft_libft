/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:20:12 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 23:48:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

void	ft_pkt_print_icmp(t_icmphdr_echo *pkt)
{
	ft_printf(FMT_ICMPHDR_ECHO, pkt->type, pkt->code, pkt->checksum,
		pkt->identifier, pkt->sequence);
}
