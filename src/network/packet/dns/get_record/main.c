/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:47:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/03 14:05:28 by brda-sil         ###   ########.fr       */
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

char	*get_name_by_offset(t_uint16 offset, t_dnsr_struct *dnsr)
{
	t_dnsr_name	*tmp;

	tmp = dnsr->names;
	while (tmp)
	{
		if (tmp->offset == offset)
			return (tmp->name);
		tmp = tmp->next;
	}
	return (FT_NULL);
}

t_uint32	get_dnsr_name(t_dnsr_struct *dnsr)
{
	t_dnsr_name	*name;

	name = (t_dnsr_name *)ft_calloc(1, sizeof(t_dnsr_name));
	name->offset = dnsr->offset;
	if (dnsr->data[dnsr->offset] & 0xc0)
	{
		ft_printf("get_dnsr_name: compression\n");
		name->name = get_name_by_offset(ft_htons(dnsr->data[dnsr->offset] & 0x3f), dnsr);
		return (0);
	}
	else
	{
		ft_printf("get_dnsr_name: no compression\n");
		ft_pkt_get_dnsr_name(dnsr->data, &name->name);
		append_name(name, &dnsr);
		return (ft_strlen(name->name) + 2);
	}
}

t_uint16	get_dnsr_type(t_dnsr_struct *dnsr, t_uint16 name_len)
{
	t_uint16	index;

	index = dnsr->offset + name_len;
	return (ft_htons(dnsr->data[index] | dnsr->data[index + 1] << 8));
}

t_uint16	get_dnsr_class(t_dnsr_struct *dnsr, t_uint16 name_len)
{
	t_uint16	index;

	index = dnsr->offset + name_len;
	return (ft_htons(dnsr->data[index + 2] | dnsr->data[index + 3] << 8));
}

char	*get_last_name(t_dnsr_struct *dnsr)
{
	t_dnsr_name	*tmp;

	tmp = dnsr->names;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->name);

}

t_bool	get_dnsr_record(t_dnsr_struct *dnsr, t_uint16 type)
{
	t_uint16	name_len;
	t_uint16	tmp_type;

	name_len = get_dnsr_name(dnsr);
	if (!name_len)
	{
		ft_printf("get_dnsr_record: get_dnsr_name: failed\n");
		return (FALSE);
	}
	ft_printf("Name:   %s\n", dnsr->names->name);
	tmp_type = get_dnsr_type(dnsr, name_len);
	ft_printf("Type:   %d\n", tmp_type);
	ft_printf("Class:  %d\n", get_dnsr_class(dnsr, name_len));
	ft_printf("Offset: %d\n\n", dnsr->offset);
	dnsr->offset += name_len + 4;
	tmp_type = 0;
	while (tmp_type != type)
	{
		name_len = get_dnsr_name(dnsr);
		if (!name_len)
		{
			name_len += 2;
			ft_printf("Name:   %s\n", get_last_name(dnsr));
			tmp_type = get_dnsr_type(dnsr, name_len);
			ft_printf("Type:   %d\n", tmp_type);
			ft_printf("Class:  %d\n", get_dnsr_class(dnsr, name_len));
			ft_printf("Offset: %d\n", dnsr->offset);
			dnsr->offset += 2;
		}
		else
		{
			ft_printf("Name:   %s\n", get_last_name(dnsr));
			tmp_type = get_dnsr_type(dnsr, name_len);
			ft_printf("Type:   %d\n", tmp_type);
			ft_printf("Class:  %d\n", get_dnsr_class(dnsr, name_len));
			ft_printf("Offset: %d\n", dnsr->offset);
			dnsr->offset += name_len + 4;
		}
	}
	return (FALSE);
}

char	*ft_dns_get_record(t_packet *pkt, t_uint16 type)
{
	t_dnsr_struct	dnsr;

	ft_pkt_print_raw(1, (char *)pkt->data, 0xff);

	dnsr.data = ft_pkt_get_dns_data(pkt);
	dnsr.names = FT_NULL;
	dnsr.offset = 0;

	while (get_dnsr_record(&dnsr, type))
		ft_printf("get record\n");

	return (FT_NULL);
}
