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

t_packet	ft_pkt_get(void)
{
	t_packet	packet;

	ft_bzero(&packet, sizeof(t_packet));
	return (packet);
}
