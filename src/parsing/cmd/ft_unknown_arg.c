/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unknown_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:35:55 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 06:00:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_unknown_arg(void)
{
	t_opts		*opts;

	opts = ft_get_opts(0);
	if (opts->err_param_name)
		ft_perr(PROG_NAME ": unrecognized option '%s'\n", opts->err_param_name);
	else if (opts->err_param_short)
		ft_perr(PROG_NAME ": invalid option -- '%c'\n", opts->err_param_short);
	ft_try_help_usage();
}
