/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:10:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 03:51:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

static	t_bool	isgood_optlong(char *arg)
{
	t_opts	*opts;
	t_size	arg_len;
	t_opt	*ptr;

	arg_len = ft_strlen(arg);
	opts = ft_sin_opts(FALSE);
	ptr = opts->opt;
	while (ptr)
	{
		if (ptr->name && !ft_strncmp(ptr->name, arg, arg_len))
		{
			ptr->is_present = TRUE;
			opts->last_parsed_opt = ptr;
			ft_optorder_add(OPT_ORD_OPT, arg);
			return (TRUE);
		}
		ptr = ptr->next;
	}
	return (FALSE);
}

t_bool	ft_is_optlong(char *arg)
{
	t_opts	*opts;

	if (!arg || arg[0] != '-' || !arg[1] || arg[1] != '-')
		return (FALSE);
	opts = ft_sin_opts(FALSE);
	if (!isgood_optlong(arg + 2))
	{
		opts->err ^= ERR_UNK_OPT;
		opts->err_param_name = arg;
		return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_optlong_parse(char *arg)
{
	t_opts	*opts;

	opts = ft_sin_opts(FALSE);
	if (!ft_is_optlong(arg))
	{
		if (opts->err ^ ERR_UNK_OPT)
			return (FALSE);
	}
	return (TRUE);
}
