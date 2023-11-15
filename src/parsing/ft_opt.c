/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:18:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_opts	*ft_get_opts(t_bool free)
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
