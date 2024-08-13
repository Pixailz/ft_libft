/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i4toh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:56:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/03 13:57:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"
#include <arpa/inet.h> //for inet_pton()
#include <netdb.h> // for NI_MAXHOST, getnameinfo() and gai_strerror()

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	test_getnameinfo(char *ip);

int	test_i4toh(t_int4 ip)
{
	char	*name;
	char	*ip_str;

	ip_str = ft_getip_str(ft_htonl(ip));
	name = ft_i4toh(ip);
	// test_getnameinfo(ip_str);
	free(ip_str);
	ft_putip_fd(ip, 1);
	ft_printf("%s -> ", CSI "20G");
	if (!name)
	{
		ft_putstr_fd("error\n", 1);
		return (1);
	}
	ft_putstr_fd(name, 1);
	ft_putstr_fd("\n", 1);
	free(name);
	return (0);
}

int	ci_test(void)
{
	int	ret;

	ret = 0;
	for (int i = 0; i < 1; i++)
	{
		// ret += test_i4toh(0xd83ad6ae);
		// ret += test_i4toh(0x4d9aed79);
		// ret += test_i4toh(0xd5f50030);
		ret += test_i4toh(0xc0b251f9);
		// ret += test_i4toh(0xc0b26915);
	}
	// ret += test_i4toh(0xc0a80001); // not working for local ip
	// ret += test_i4toh(0xc0a8000c);
	return (ret);
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
