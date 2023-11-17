/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_other_last_parsed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:10:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 12:45:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optother_parse_flag(t_opt_value *src, t_opt_value *dst)
{
	if (dst)
		ft_optvalue_append(dst, src);
	else
		dst = src;
}

void	ft_opt_other_last_parsed(t_opt_value *src)
{
	t_opts	*opts;

	opts = ft_get_opts(0);
	if (opts->last_parsed_opt->flag & OPT_FLAG)
		ft_optother_parse_flag(src, opts->last_parsed_opt->value);
	else if (opts->last_parsed_opt->flag & OPT_SINGLE)
	{
		if (opts->last_parsed_opt->value)
			free(opts->last_parsed_opt->value);
		opts->last_parsed_opt->value = src;
		opts->last_parsed_opt = FT_NULL;
	}
}
