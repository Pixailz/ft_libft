/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 06:00:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_bin	ft_opt_post_parse(t_bin (*post_func)())
{
	t_opts		*opts;
	t_bin		retv;

	if (ft_opt_post_parse_cmd())
		return (BIT_01);
	opts = ft_get_opts(0);
	if (opts->err & ERR_UNK_OPT)
	{
		ft_unknown_arg();
		return (BIT_02);
	}
	if (post_func == FT_NULL)
		retv = 0;
	else
		retv = post_func();
	return (retv);
}
