/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_other_last_parsed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:10:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/27 16:29:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optother_parse_flag(t_opt_value *src, t_opt_value **dst)
{
	if (*dst)
		ft_optvalue_append(*dst, src);
	else
		*dst = src;
}

void	ft_optother_parse_single(t_opt_value *src, t_opt **dst)
{
	if ((*dst)->value)
		free((*dst)->value);
	(*dst)->value = src;
	*dst = FT_NULL;
}

void	ft_optother_parse_multiple(t_opt_value *src, t_opt_value **dst)
{
	if (*dst)
		ft_optvalue_append(*dst, src);
	else
		*dst = src;
}

void	ft_opt_other_last_parsed(t_opt_value *src)
{
	t_opts	*opts;

	opts = ft_get_opts(0);
	if (opts->last_parsed_opt->flag & OPT_FLAG)
	{
		ft_optother_parse_flag(src, &opts->value);
		opts->last_parsed_opt = FT_NULL;
	}
	else if (opts->last_parsed_opt->flag & OPT_SINGLE)
		ft_optother_parse_single(src, &opts->last_parsed_opt);
	else if (opts->last_parsed_opt->flag & OPT_MULTIPLE)
		ft_optother_parse_multiple(src, &opts->last_parsed_opt->value);
}
