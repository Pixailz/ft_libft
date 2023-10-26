/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_short.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:10:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:12:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

static	t_bool	isgood_optshort(char arg)
{
	t_opts	*opts;
	t_opt	*ptr;

	opts = ft_sin_opts(FALSE);
	ptr = opts->opt;
	while (ptr)
	{
		if (ptr->opt_short && ptr->opt_short == arg)
		{
			ptr->is_present = TRUE;
			if (ptr->flag ^ OPT_FLAG)
				opts->last_parsed_opt = ptr;
			return (TRUE);
		}
		ptr = ptr->next;
	}
	return (FALSE);
}

t_bool	ft_is_optshort(char *arg)
{
	int		counter;
	t_opts	*opts;

	if (!arg || arg[0] != '-' || (arg[1] && arg[1] == '-'))
		return (FALSE);
	counter = 1;
	opts = ft_sin_opts(FALSE);
	while (arg[counter])
	{
		if (!isgood_optshort(arg[counter]))
		{
			opts->err ^= ERR_UNK_OPT;
			opts->err_param = &arg[counter];
			return (FALSE);
		}
		counter++;
	}
	return (TRUE);
}

t_bool	ft_optshort_parse(char *arg)
{
	t_opts	*opts;

	opts = ft_sin_opts(FALSE);
	if (!ft_is_optshort(arg))
	{
		if (opts->err & ERR_UNK_OPT)
			ft_sin_opt_perr();
		else
			return (FALSE);
	}
	return (TRUE);
}
