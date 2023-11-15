/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin_opt_perr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:40:52 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:20:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_opt_perr(void)
{
	t_opts	*opts;

	opts = ft_get_opts(FALSE);
	if (opts->err & ERR_UNK_OPT)
	{
		if (opts->err_param_name)
			ft_perr("unknown params %s\n", opts->err_param_name);
		else if (opts->err_param_short)
			ft_perr("unknown params %s\n", opts->err_param_short);
	}
}
