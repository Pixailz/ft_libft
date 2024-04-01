/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:54 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 04:28:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

static void	ft_optparse_one(void)
{
	t_opts				*opts;
	char				*arg;

	opts = ft_get_opts(FALSE);
	arg = opts->av[opts->parse_index];
	if (!ft_strlen(arg))
		return ;
	else if (!ft_strcmp(arg, "--"))
	{
		opts->opt_finished = TRUE;
		opts->last_parsed_opt = FT_NULL;
		ft_optorder_add(OPT_ORD_END, arg);
	}
	else if (ft_optshort_parse(arg))
		return ;
	else if (ft_optlong_parse(arg))
		return ;
	else
		ft_optother_parse(arg);
}

void	ft_optparse(int ac, char **av)
{
	t_opts				*opts;

	ft_optadd_cmd("version", 'V', ft_version);
	opts = ft_get_opts(FALSE);
	opts->ac = ac - 1;
	opts->av = av + 1;
	while (opts->parse_index < opts->ac)
	{
		ft_optparse_one();
		if (opts->err & ERR_UNK_OPT)
			break ;
		opts->parse_index++;
	}
}
