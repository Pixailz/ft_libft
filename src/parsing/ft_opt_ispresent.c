/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_ispresent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:21:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 02:54:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

t_bool	ft_opt_ispresent(char *name)
{
	t_opt	*opt;

	opt = ft_optget(name);
	return (opt->is_present);
}
