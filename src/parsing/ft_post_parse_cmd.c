/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_parse_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:38:09 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/01 03:39:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_bin	ft_opt_exec_cmd(void)
{
	t_opts		*opts;
	t_opt_order	*ptr;

	opts = ft_get_opts(0);
	ptr = opts->opt_order;
	while (ptr)
	{
		if (ptr->opt && !ft_strcmp(ptr->opt->name, opts->target_cmd))
			return (ptr->opt->cmd());
		ptr = ptr->next;
	}
	return (0);
}

t_bool	ft_opt_post_parse_cmd(void)
{
	t_opts		*opts;
	t_opt_order	*ptr;

	opts = ft_get_opts(0);
	ptr = opts->opt_order;
	while (ptr)
	{
		if (ptr->opt && ptr->opt->flag == OPT_CMD)
		{
			opts->target_cmd = ptr->opt->name;
			return (TRUE);
		}
		ptr = ptr->next;
	}
	return (FALSE);
}
