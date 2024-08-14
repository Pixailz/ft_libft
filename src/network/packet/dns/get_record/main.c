/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:47:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 15:49:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

void	append_name(t_dnsr_name *name, t_dnsr_struct **dnsr)
{
	t_dnsr_name	*tmp;

	if (!(*dnsr)->names)
	{
		(*dnsr)->names = name;
		return ;
	}
	tmp = (*dnsr)->names;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = name;
}

t_uint16	get_dns_offset(t_dnsr_struct *dnsr)
{
	t_uint16	offset;

	offset = dnsr->data[dnsr->offset] << 8 | dnsr->data[dnsr->offset + 1];
	return (0xc000 ^ offset);
}

char	*get_name_by_offset(t_dnsr_struct *dnsr)
{
	t_dnsr_name	*tmp;
	t_uint16	offset;

	offset = get_dns_offset(dnsr);
	tmp = dnsr->names;
	while (tmp)
	{
		if (tmp->offset == offset)
			return (ft_strdup(tmp->name));
		tmp = tmp->next;
	}
	return (FT_NULL);
}

t_uint16	get_dnsr_type(t_dnsr_struct *dnsr)
{
	t_uint16	index;

	index = dnsr->offset;
	return (ft_htons(dnsr->data[index] | dnsr->data[index + 1] << 8));
}

t_uint16	get_dnsr_class(t_dnsr_struct *dnsr)
{
	t_uint16	index;

	index = dnsr->offset + 2;
	return (ft_htons(dnsr->data[index] | dnsr->data[index + 1] << 8));
}

t_uint16	get_dnsr_ttl(t_dnsr_struct *dnsr)
{
	t_uint16	index;
	t_uint32	ttl;

	index = dnsr->offset + 4;
	ttl = dnsr->data[index] << 24;
	ttl |= dnsr->data[index + 1] << 16;
	ttl |= dnsr->data[index + 2] << 8;
	ttl |= dnsr->data[index + 3];
	return (ttl);
}

t_uint16	get_dnsr_rlength(t_dnsr_struct *dnsr)
{
	t_uint16	index;

	index = dnsr->offset + 8;
	return (ft_htons(dnsr->data[index] | dnsr->data[index + 1] << 8));
}

t_dnsr_name	*get_last_name(t_dnsr_struct *dnsr)
{
	t_dnsr_name	*tmp;

	tmp = dnsr->names;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);

}

void	ft_free_dnsr(t_dnsr_struct *dnsr)
{
	t_dnsr_name	*tmp;
	t_dnsr_name	*next;

	tmp = dnsr->names;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->name)
		{
			free(tmp->name);
			tmp->name = FT_NULL;
		}
		if (tmp->rdata)
		{
			free(tmp->rdata);
			tmp->rdata = FT_NULL;
		}
		free(tmp);
		tmp = FT_NULL;
		tmp = next;
	}
}

char	**ft_dns_get_record_ptr(t_packet *pkt)
{
	t_dnsr_struct	dnsr;
	t_dnshdr		*header;
	char			**names;

	header = ft_pkt_get_dns(pkt);
	dnsr.data = (unsigned char *)header;
	// ft_pkt_print_raw(1, dnsr.data, 0xff);
	dnsr.names = FT_NULL;
	dnsr.offset = PACK_LEN_DNS;
	get_dns_qdrecord(&dnsr, ft_htons(header->question_count));
	get_dns_anrecord(&dnsr, ft_htons(header->answer_count));
	names = ft_dns_extract_answer_ptr(dnsr.names);
	ft_free_dnsr(&dnsr);
	return (names);
}

t_int4	ft_dns_get_record_a(t_packet *pkt)
{
	t_dnsr_struct	dnsr;
	t_dnshdr		*header;
	t_int4			ip;

	header = ft_pkt_get_dns(pkt);
	dnsr.data = (unsigned char *)header;
	// ft_pkt_print_raw(1, dnsr.data, 0xff);
	dnsr.names = FT_NULL;
	dnsr.offset = PACK_LEN_DNS;
	get_dns_qdrecord(&dnsr, ft_htons(header->question_count));
	get_dns_anrecord(&dnsr, ft_htons(header->answer_count));
	ip = ft_dns_extract_answer_a(dnsr.names);
	ft_free_dnsr(&dnsr);
	return (ip);
}
