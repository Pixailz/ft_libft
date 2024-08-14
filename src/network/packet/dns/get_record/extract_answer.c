/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_answer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:47:35 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 16:06:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

t_uint16	get_answer_nb(t_dnsr_name *name, t_uint16 type)
{
	t_uint16	counter;

	counter = 0;
	while (name)
	{
		if (name->type == type && name->rsc_type == DNS_RTYPE_ANSWER)
			counter++;
		name = name->next;
	}
	return (counter);
}

char	**ft_dns_extract_answer_ptr(t_dnsr_name *name)
{
	t_uint16	count;
	char		**names;

	count = get_answer_nb(name, DNS_TYPE_PTR);
	names = (char **)ft_calloc(count + 1, sizeof(char *));
	names[count] = FT_NULL;
	count = 0;
	while (name)
	{
		if (name->type == DNS_TYPE_PTR && name->rsc_type == DNS_RTYPE_ANSWER)
		{
			names[count] = ft_strdup(name->rdata);
			count++;
		}
		name = name->next;
	}

	return (names);
}

t_int4 ft_dns_extract_answer_a(t_dnsr_name *name)
{
	while (name)
	{
		if (name->type == DNS_TYPE_A && name->rsc_type == DNS_RTYPE_ANSWER)
		{
			return(ft_atou(name->rdata));
		}
		name = name->next;
	}
	return (0);
}
