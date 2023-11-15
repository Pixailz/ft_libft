/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:31:01 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 06:19:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_opt	*ft_optget(char *name)
{
	t_opt	*opt;
	t_size	name_len;

	name_len = ft_strlen(name);
	opt = ft_get_opts(FALSE)->opt;
	while (opt)
	{
		if (opt->name && !ft_strncmp(opt->name, name, name_len))
			return (opt);
		opt = opt->next;
	}
	return (FALSE);
}
