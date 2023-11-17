/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:11:46 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/17 06:36:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network/ipv4.h"

static void	ntop_part(t_int1 n, t_size *i, char *ip_str)
{
	if (n >= 10)
		ntop_part(n / 10, i, ip_str);
	ip_str[*i] = '0' + n % 10;
	(*i)++;
}

void	ft_ntop(t_bin pf, t_int4 ip, char *ip_str)
{
	int		lvl;
	t_size	i;

	(void)pf;
	ft_memset(ip_str, 0, INET_ADDRSTRLEN);
	i = 0;
	lvl = 0;
	while (lvl < 4)
	{
		ntop_part(ft_int4_dcomp(ip, lvl), &i, ip_str);
		lvl++;
		if (lvl != 4)
		{
			ip_str[i] = '.';
			i++;
		}
	}
}
