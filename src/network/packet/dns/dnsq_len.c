/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dnsq_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:19:51 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_size	ft_pkt_dnsq_len(t_packet pack)
{
	t_size	len;

	len = 0;
	while (pack.data[PACK_LEN_IP + PACK_LEN_UDP + PACK_LEN_DNS + len])
		len++;
	return (len + 5);
}
