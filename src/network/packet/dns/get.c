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

#include "libft_network.h"

t_dnshdr	*ft_pkt_get_dns(t_packet *packet)
{
	return ((t_dnshdr *)(packet->data + PACK_LEN_IP + PACK_LEN_UDP));
}

unsigned char	*ft_pkt_get_dns_data(t_packet *pack)
{
	return ((unsigned char *)(pack->data + PACK_LEN_IP + PACK_LEN_UDP + PACK_LEN_DNS));
}
