/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 03:54:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_bin	ft_opt_post_parse(void)
{
	t_opts		*opts;

	if (ft_opt_post_parse_cmd())
		return (BIT_01);
	opts = ft_get_opts(0);
	if (opts->err & ERR_UNK_OPT)
	{
		ft_unknown_arg();
		return (BIT_02);
	}
	if (!opts->value)
	{
		ft_perr("%s", PROG_NAME SEP "Argument needed\n");
		ft_try_help_usage();
		return (BIT_03);
	}
	return (BIT_00);
}
