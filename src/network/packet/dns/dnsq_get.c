/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dnsq_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:34:47 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

int	ft_pkt_dnsq_get(unsigned char *data, t_dnsq *dnsq)
{
	int	i;

	i = ft_pkt_get_dnsr_name(data, &dnsq->name);
	i += 1;
	dnsq->type = ft_htons(*(t_uint16 *)(data + i));
	i += 2;
	dnsq->class = ft_htons(*(t_uint16 *)(data + i));
	i += 2;
	return (i);
}
