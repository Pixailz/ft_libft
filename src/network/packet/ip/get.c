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

t_iphdr	*ft_pkt_get_ip(t_packet *packet)
{
	return ((t_iphdr *)packet->data);
}
