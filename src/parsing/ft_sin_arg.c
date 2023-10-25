/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/25 12:11:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_opt	*ft_sin_arg(t_opt *opt)
{
	static t_opt	*opts = FT_NULL;

	if (!opts)
		opts = opt;
	return (opts);
}

void	ft_sin_free_arg(void)
{
	t_opt	*opts;
	t_opt	*tmp;
	int		counter;

	opts = ft_sin_arg(FT_NULL);
	while (opts)
	{
		tmp = opts->next;
		if (opts->value)
		{
			counter = -1;
			while (opts->value[++counter])
				free(opts->value[counter]);
			free(opts->value);
		}
		free(opts);
		opts = tmp;
	}
}
