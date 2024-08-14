/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:23:03 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 16:40:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

void	get_dns_answer_name(t_dnsr_struct *dnsr)
{
	t_dnsr_name	*name;
	t_uint32	to_add;
	t_uint32	name_len;

	name = (t_dnsr_name *)ft_calloc(1, sizeof(t_dnsr_name));
	name->offset = dnsr->offset;
	to_add = 8;
	name_len = ft_dns_getlabel_ptr(dnsr->data, dnsr->offset, &name->name, 0);
	append_name(name, &dnsr);
	dnsr->offset += name_len;
	name->rsc_type = DNS_RTYPE_ANSWER;
	name->type = get_dnsr_type(dnsr);
	name->class = get_dnsr_class(dnsr);
	name->ttl = get_dnsr_ttl(dnsr);
	name->rlength = get_dnsr_rlength(dnsr);
	dnsr->offset += to_add + 2;
	switch (name->type)
	{
		case DNS_TYPE_A:
			ft_dns_getlabel_a(dnsr->data, dnsr->offset, &name->rdata);
			break;
		case DNS_TYPE_PTR:
			ft_dns_getlabel_ptr(dnsr->data, dnsr->offset, &name->rdata, name->rlength);
			break;
	}
	dnsr->offset += name->rlength;
}

void	print_dns_answer_name(t_dnsr_name *name)
{
	ft_printf("Name:          %s\n", name->name);
	ft_printf("Type:          %d\n", name->type);
	ft_printf("Class:         %d\n", name->class);
	ft_printf("TTL:           %d\n", name->ttl);
	ft_printf("Data length:   %d\n", name->rlength);
	ft_printf("Data:          %s\n", name->rdata);
	ft_printf("Offset:        %d\n", name->offset);
	ft_putendl_fd("", 1);
}

t_bool	get_dns_anrecord(t_dnsr_struct *dnsr, t_uint16 count)
{
	int			counter = 0;

	// ft_printf("ANSWER COUNT: %d\n", count);
	while (counter++ < count)
	{
		get_dns_answer_name(dnsr);
		// print_dns_answer_name(get_last_name(dnsr));
	}
	return (FALSE);
}
