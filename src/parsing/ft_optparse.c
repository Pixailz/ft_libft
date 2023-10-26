/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:54 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:19:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

static t_bool	ft_optparse_one(void)
{
	t_opts	*opts;
	char	*arg;

	opts = ft_sin_opts(FALSE);
	arg = opts->av[opts->parse_index];
	if (!ft_strcmp(arg, "--"))
	{
		opts->opt_finished = TRUE;
		opts->last_parsed_opt = FT_NULL;
	}
	else if (ft_optshort_parse(arg))
		(void)arg;
	else if (ft_optlong_parse(arg))
		(void)arg;
	else
		ft_optother_parse(arg);
	opts->parse_index++;
	return (opts->parse_index != opts->ac);
}

void	ft_optparse(void)
{
	while (ft_optparse_one())
	{
	}
}
