/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/27 15:18:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_print_opt_value(t_opt_value *value)
{
	t_opt_value	*ptr;

	ptr = value;
	ft_printf("{ ");
	while (ptr)
	{
		ft_printf("\"%s\"", ptr->value);
		ptr = ptr->next;
		if (ptr)
			ft_printf(", ");
	}
	ft_printf(" }\n");
}

void	ft_print_opt(t_opt opt)
{
	if (opt.opt_short)
		ft_printf("'%c' short of ", opt.opt_short);
	ft_printf("\"%s\" | ", opt.name);
	if (opt.flag & OPT_FLAG)
		ft_printf("F");
	if (opt.flag & OPT_SINGLE)
		ft_printf("S");
	if (opt.flag & OPT_MULTIPLE)
		ft_printf("M");
	ft_printf(" | ");
	if (opt.is_present)
		ft_printf("is present | ");
	ft_print_opt_value(opt.value);
}

void	ft_print_opts_order(t_opt_order *ptr)
{
	t_uint16	counter;

	counter = 0;
	ft_printf("order of apparition\n");
	while (ptr)
	{
		counter++;
		ft_printf("%d. ", counter);
		if (ptr->type == OPT_ORD_OPT)
		{
			ft_printf("(OPT) ");
			ft_print_opt(*ptr->opt);
		}
		else if (ptr->type == OPT_ORD_VAL)
			ft_printf("(VALUE) %s\n", ptr->value);
		else if (ptr->type == OPT_ORD_END)
			ft_printf("(END)\n");
		ptr = ptr->next;
	}
}

void	ft_print_all_opt(t_opts *opts)
{
	t_opt	*ptr;

	ft_print_opts_order(opts->opt_order);
	ptr = opts->opt;
	ft_printf("ALL OPTS\n");
	while (ptr)
	{
		ft_print_opt(*ptr);
		ptr = ptr->next;
	}
}

void	ft_print_opts(void)
{
	t_opts	*opts;

	opts = ft_get_opts(FALSE);
	if (opts->err)
	{
		ft_printf("ERROR %d | %s | %c\n", opts->err, \
								opts->err_param_name, opts->err_param_short);
	}
	if (opts->last_parsed_opt)
	{
		ft_printf("last_parsed_opt: ");
		ft_print_opt(*opts->last_parsed_opt);
	}
	if (opts->value)
	{
		ft_printf("value without opt: ");
		ft_print_opt_value(opts->value);
	}
	ft_print_all_opt(opts);
}
