/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ptr_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:32:26 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 23:51:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

char	*ft_dns_get_ptr_record(t_packet *pkt)
{
	unsigned char	*dns_data;
	char			*name;
	int				i;

	dns_data = ft_pkt_get_dns_data(pkt);
	i = ft_pkt_get_dnsr_name(dns_data, &name);
	free(name);
	i += 17;
	i += ft_pkt_get_dnsr_name(dns_data + i, &name);
	if (!ft_strlen(name))
		return (FT_NULL);
	return (name);
}
