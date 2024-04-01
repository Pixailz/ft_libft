/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:54 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 03:56:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optadd_append(t_opt *end)
{
	t_opts	*opts;
	t_opt	*ptr;

	opts = ft_get_opts(FALSE);
	if (!opts->opt)
	{
		opts->opt = end;
	}
	else
	{
		ptr = opts->opt;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = end;
	}
}

void	ft_optadd(char *name, char opt_short, t_uint8 flag)
{
	t_opt	*tmp;

	tmp = (t_opt *)ft_calloc(sizeof(t_opt), 1);
	tmp->name = name;
	tmp->opt_short = opt_short;
	tmp->flag = flag;
	tmp->cmd = 0;
	ft_optadd_append(tmp);
}

void	ft_optadd_cmd(char *name, char opt_short, t_opt_cmd opt_cmd)
{
	t_opt	*tmp;

	tmp = (t_opt *)ft_calloc(sizeof(t_opt), 1);
	tmp->name = name;
	tmp->opt_short = opt_short;
	tmp->flag = OPT_CMD;
	tmp->cmd = opt_cmd;
	ft_optadd_append(tmp);
}
