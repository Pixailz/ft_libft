/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dnsr_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:34:47 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 02:32:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

static int	get_dnsr_response_info_value(unsigned char *data, t_dnsr *dnsr)
{
	char	*ptr;
	if (dnsr->type == DNS_TYPE_A)
	{
		dnsr->value = ft_calloc(5, sizeof(t_uint8));
		ft_memcpy(dnsr->value, data, 4);
		ptr = dnsr->value + 4;
		*ptr = 0;
		return (4);
	}
	else if (dnsr->type == DNS_TYPE_CNAME)
		return (dnsr->rdlength);
	return (1);
}

static int	get_dnsr_response_info(unsigned char *data, t_dnsr *dnsr)
{
	t_dnsr	tmp;

	tmp.type = ft_htons(*(t_uint16 *)(&data[2]));
	tmp.class = ft_htons(*(t_uint16 *)(&data[4]));
	tmp.ttl = ft_htonl(*(t_uint32 *)(&data[6]));
	tmp.rdlength = ft_htons(*(t_uint16 *)(&data[10]));
	if (tmp.type == DNS_TYPE_A)
	{
		dnsr->type = tmp.type;
		dnsr->class = tmp.class;
		dnsr->ttl = tmp.ttl;
		dnsr->rdlength = tmp.rdlength;
		return (get_dnsr_response_info_value(data + 12, dnsr) + 12);
	}
	else
		return (get_dnsr_response_info_value(data + 12, &tmp) + 12);
	return (0);
}

int	ft_pkt_dnsr_get(
		unsigned char *data,
		t_uint16 rc,
		t_dnsr *dnsr
	)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_bzero(dnsr, sizeof(t_dnsr));
	while (j < rc)
	{
		i += get_dnsr_response_info(data + i, dnsr);
		j++;
	}
	return (i);
}
