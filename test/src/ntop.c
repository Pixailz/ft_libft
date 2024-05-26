/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

#include <arpa/inet.h>

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	test_ntop(t_int1 n1, t_int1 n2, t_int1 n3, t_int1 n4)
{
	t_int4	ip;
	char	ip_str[INET_ADDRSTRLEN];

	ip = ft_int4_comp(n4, n3, n2, n1);
	ft_ntop(AF_INET, ip, ip_str);
	ft_printf("ip_str %s\n", ip_str);
}

int	ci_test(void)
{
	test_ntop(127, 0, 0, 1);
	test_ntop(192, 168, 0, 1);
	test_ntop(10, 11, 12, 13);
	return (0);
}

int	interactive(void)
{
	ft_perr("parsing", 2);
	return (0);
}

int	main(void)
{
	if (CI_TEST)
		return (ci_test());
	else
		return (interactive());
	return (0);
}
