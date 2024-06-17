/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:49:44 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 17:52:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_size ft_opts_len(t_opts *opts)
{
	t_opt_value	*ptr;
	int			nb_opts;

	ptr = opts->value;
	nb_opts = 0;
	while (ptr)
	{
		if (ptr->value)
			nb_opts++;
		ptr = ptr->next;
	}
	return (nb_opts);
}

