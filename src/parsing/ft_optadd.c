/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:54 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:09:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optadd(char *opt_long, char opt_short, t_uint8 flag)
{
	t_opts	*opts;
	t_opt	*tmp;
	t_opt	*ptr;

	tmp = (t_opt *)ft_calloc(sizeof(t_opt), 1);
	tmp->opt_long = opt_long;
	tmp->opt_short = opt_short;
	tmp->flag = flag;
	opts = ft_sin_opts(FALSE);
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