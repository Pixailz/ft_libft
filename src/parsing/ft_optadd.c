/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:54 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:19:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optadd(char *name, char opt_short, t_uint8 flag)
{
	t_opts	*opts;
	t_opt	*tmp;
	t_opt	*ptr;

	tmp = (t_opt *)ft_calloc(sizeof(t_opt), 1);
	tmp->name = name;
	tmp->opt_short = opt_short;
	tmp->flag = flag;
	opts = ft_get_opts(FALSE);
	if (!opts->opt)
	{
		opts->opt = tmp;
	}
	else
	{
		ptr = opts->opt;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
	}
}
