/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_question.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:23:03 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 15:49:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

void	get_dns_question_name(t_dnsr_struct *dnsr)
{
	t_dnsr_name	*name;
	t_uint32	to_add;
	t_uint32	name_len;

	name = (t_dnsr_name *)ft_calloc(1, sizeof(t_dnsr_name));
	name->offset = dnsr->offset;
	to_add = 4;
	name_len = ft_dns_getlabel_ptr(dnsr->data, dnsr->offset, &name->name, 0);
	append_name(name, &dnsr);
	dnsr->offset += name_len + 1;
	name->rsc_type = DNS_RTYPE_QUESTION;
	name->type = get_dnsr_type(dnsr);
	name->class = get_dnsr_class(dnsr);
	dnsr->offset += to_add;
}

void	print_dns_question_name(t_dnsr_name *name)
{
	ft_printf("Name:          %s\n", name->name);
	ft_printf("Type:          %d\n", name->type);
	ft_printf("Class:         %d\n", name->class);
	ft_printf("Offset:        %d\n", name->offset);
}

t_bool	get_dns_qdrecord(t_dnsr_struct *dnsr, t_uint16 count)
{
	int			counter = 0;

	// ft_printf("QUESTION COUNT: %d\n", count);
	while (counter++ < count)
	{
		get_dns_question_name(dnsr);
		// print_dns_question_name(get_last_name(dnsr));
	}
	return (FALSE);
}
