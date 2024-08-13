/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:03 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 19:19:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_free_opt_value(t_opt_value *value)
{
	t_opt_value	*ptr;

	while (value)
	{
		ptr = value->next;
		free(value);
		value = ptr;
	}
}

void	ft_free_opt_order(t_opt_order *order)
{
	t_opt_order	*ptr;

	while (order)
	{
		ptr = order->next;
		free(order);
		order = ptr;
	}
}

void	ft_free_opt(t_opt *opt)
{
	if (opt)
	{
		ft_free_opt_value(opt->value);
		opt->value = FT_NULL;
	}
	free(opt);
}

void	ft_free_opts(void)
{
	t_opts		*opts;
	t_opt		*tmp;

	opts = ft_get_opts(FALSE);
	while (opts->opt)
	{
		tmp = opts->opt->next;
		ft_free_opt(opts->opt);
		opts->opt = tmp;
	}
	ft_free_opt_value(opts->value);
	ft_free_opt_order(opts->opt_order);
	free(opts);
	ft_get_opts(TRUE);
}
