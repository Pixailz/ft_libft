/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:10:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 12:26:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optvalue_append(t_opt_value *dst, t_opt_value *src)
{
	t_opt_value	*ptr;

	ptr = dst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = src;
}

void	ft_optother_parse(char *arg)
{
	t_opts		*opts;
	t_opt_value	*src;

	opts = ft_get_opts(FALSE);
	src = (t_opt_value *)ft_calloc(sizeof(t_opt_value), 1);
	src->value = arg;
	if (opts->last_parsed_opt)
		ft_opt_other_last_parsed(src);
	else
	{
		if (opts->value)
			ft_optvalue_append(opts->value, src);
		else
			opts->value = src;
	}
	ft_optorder_add(OPT_ORD_VAL, arg);
}
