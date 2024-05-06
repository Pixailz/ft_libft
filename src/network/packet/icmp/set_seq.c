/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_seq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:54:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/06 22:41:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/packet.h"

void	ft_pkt_icmp_set_seq(t_icmphdr_echo *packet, t_int32 seq)
{
	packet->sequence = ft_htons(seq);
}
