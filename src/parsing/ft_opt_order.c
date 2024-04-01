/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:18:37 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:19:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optorder_add(t_opt_order_type type, char *val)
{
	t_opts		*opts;
	t_opt_order	*tmp;
	t_opt_order	*ptr;

	opts = ft_get_opts(0);
	tmp = (t_opt_order *)ft_calloc(sizeof(t_opt_order), 1);
	tmp->type = type;
	tmp->value = val;
	tmp->opt = opts->last_parsed_opt;
	if (!opts->opt_order)
	{
		opts->opt_order = tmp;
	}
	else
	{
		ptr = opts->opt_order;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
	}
}
