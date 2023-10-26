/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optconf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:30:54 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/26 22:09:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parsing.h"

void	ft_optconf(int ac, char **av)
{
	t_opts	*opts;

	opts = ft_sin_opts(FALSE);
	opts->ac = ac;
	opts->av = av;
}
