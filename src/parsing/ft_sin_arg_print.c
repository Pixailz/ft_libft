/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin_arg_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:17:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_print_opt_value(t_opt_value *value)
{
	t_opt_value	*ptr;

	ptr = value;
	while (ptr)
	{
		ft_printf("\tvalue  %s\n", ptr->value);
		ptr = ptr->next;
	}
}

void	ft_print_opt(t_opt opt)
{
	if (opt.opt_long)
		ft_printf("opt_long   %s\n", opt.opt_long);
	if (opt.opt_short)
		ft_printf("opt_short  %c\n", opt.opt_short);
	ft_printf("flag       %d\n", opt.flag);
	ft_printf("is_present %d\n", opt.is_present);
	ft_print_opt_value(opt.value);
}

void	ft_print_opts(t_opts opts)
{
	if (opts.err)
	{
		ft_printf("opts.err %d\n", opts.err);
		ft_printf("opts.err_param %s\n", opts.err_param);
	}
	if (opts.last_parsed_opt)
		ft_printf("opts.last_parsed_opt set\n");
	if (opts.value)
	{
		ft_printf("opts.value\n");
		ft_print_opt_value(opts.value);
	}
}

void	ft_print_sin_opts(void)
{
	t_opts	*opts;
	t_opt	*ptr;

	opts = ft_sin_opts(FALSE);
	ft_print_opts(*opts);
	ptr = opts->opt;
	while (ptr)
	{
		ft_print_opt(*ptr);
		ptr = ptr->next;
	}
}
