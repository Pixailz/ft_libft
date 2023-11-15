/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin_arg_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:18:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_print_opt_value(t_opt_value *value)
{
	t_opt_value	*ptr;

	ptr = value;
	while (ptr)
	{
		ft_printf("    value  %s\n", ptr->value);
		ptr = ptr->next;
	}
}

void	ft_print_opt(t_opt opt)
{
	ft_printf("name         %s\n", opt.name);
	if (opt.opt_short)
		ft_printf("opt_short    %c\n", opt.opt_short);
	ft_printf("  flag       %d\n", opt.flag);
	ft_printf("  is_present %d\n", opt.is_present);
	ft_print_opt_value(opt.value);
}

void	ft_print_opts_order(t_opt_order *ptr)
{
	ft_printf("opts_order\n");
	while (ptr)
	{
		ft_printf("  type %d\n", ptr->type);
		ft_printf("  value %s\n", ptr->value);
		ptr = ptr->next;
	}
}

void	ft_print_opts(void)
{
	t_opts	*opts;
	t_opt	*ptr;

	opts = ft_get_opts(FALSE);
	if (opts->err)
	{
		ft_printf("opts->err %d\n", opts->err);
		ft_printf("opts->err_param_name %s\n", opts->err_param_name);
		ft_printf("opts->err_param_short %c\n", opts->err_param_short);
	}
	if (opts->last_parsed_opt)
		ft_printf("opts->last_parsed_opt set\n");
	if (opts->value)
	{
		ft_printf("opts->value\n");
		ft_print_opt_value(opts->value);
	}
	ft_print_opts_order(opts->opt_order);
	ptr = opts->opt;
	while (ptr)
	{
		ft_print_opt(*ptr);
		ptr = ptr->next;
	}
}
