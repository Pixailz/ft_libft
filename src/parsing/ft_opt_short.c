/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_short.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:10:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/27 15:40:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

static	t_bool	isgood_optshort(char arg)
{
	t_opts	*opts;
	t_opt	*ptr;

	opts = ft_get_opts(FALSE);
	ptr = opts->opt;
	while (ptr)
	{
		if (ptr->opt_short && ptr->opt_short == arg)
		{
			ptr->is_present = TRUE;
			opts->last_parsed_opt = ptr;
			ft_optorder_add(OPT_ORD_OPT, ptr->name);
			return (ptr->flag);
		}
		ptr = ptr->next;
	}
	opts->err |= ERR_UNK_OPT;
	opts->err_param_short = arg;
	return (0);
}

t_bool	ft_is_optshort(char *arg)
{
	int		counter;
	t_bin	opt_type;
	t_opts	*opts;

	if (!arg || arg[0] != '-' || (arg[1] && arg[1] == '-'))
		return (FALSE);
	counter = 1;
	opts = ft_get_opts(FALSE);
	while (arg[counter])
	{
		opt_type = isgood_optshort(arg[counter]);
		if (!opt_type)
			return (FALSE);
		if (!(opt_type & OPT_FLAG))
			break ;
		counter++;
	}
	if (arg[counter++ + 1])
		ft_optother_parse(arg + counter);
	return (TRUE);
}

t_bool	ft_optshort_parse(char *arg)
{
	t_opts	*opts;

	opts = ft_get_opts(FALSE);
	if (!ft_is_optshort(arg))
	{
		if (opts->err ^ ERR_UNK_OPT)
			return (FALSE);
	}
	return (TRUE);
}
