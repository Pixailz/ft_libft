/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:10:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_opts	*ft_sin_opts(t_bool free)
{
	static t_opts	*opts = FT_NULL;

	if (free)
	{
		opts = FT_NULL;
	}
	else
	{
		if (!opts)
		{
			opts = (t_opts *)ft_calloc(sizeof(t_opts), 1);
			opts->parse_index = 0;
			opts->err = 0;
		}
	}
	return (opts);
}

void	ft_sin_free_opt_value(t_opt_value *value)
{
	t_opt_value	*ptr;

	while (value)
	{
		ptr = value->next;
		free(value);
		value = ptr;
	}
}

void	ft_sin_free_opt(t_opt *opt)
{
	if (opt)
	{
		ft_sin_free_opt_value(opt->value);
		opt->value = FT_NULL;
	}
	free(opt);
}

void	ft_sin_free_opts(void)
{
	t_opts		*opts;
	t_opt		*tmp;

	opts = ft_sin_opts(FALSE);
	while (opts->opt)
	{
		tmp = opts->opt->next;
		ft_sin_free_opt(opts->opt);
		opts->opt = tmp;
	}
	ft_sin_free_opt_value(opts->value);
	free(opts);
	ft_sin_opts(TRUE);
}
