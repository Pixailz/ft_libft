/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_goodhost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 04:42:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/28 05:44:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/ipv4.h"

t_bool	ft_is_goodchar_host(char c)
{
	return (ft_isalnum(c) || c == '-');
}

t_bool	ft_host_check(char *fqnd)
{
	char	**splitted;
	t_size	counter;

	counter = 0;
	if (ft_get_words(fqnd, '.') < 2)
		return (0);
	splitted = ft_split(fqnd, '.');
	counter = 0;
	while (splitted[counter])
	{
		if (!ft_is_str(splitted[counter], ft_is_goodchar_host))
			return (FALSE);
		counter++;
	}
	ft_free_char_pp(splitted);
	return (TRUE);
}

t_bool	ft_is_goodhost(char *fqnd)
{
	return (ft_host_check(fqnd));
}
