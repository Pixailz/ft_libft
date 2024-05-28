/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i4toh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:56:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 23:35:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"
#include <arpa/inet.h> //for inet_pton()
#include <netdb.h> // for NI_MAXHOST, getnameinfo() and gai_strerror()

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

# define TARGET_IP	0xacd914ce

void	test_getnameinfo(char *ip);

int	test_i4toh(t_int4 ip)
{
	char	*name;
	char	*ip_str;

	ip_str = ft_getip_str(ft_htonl(ip));
	name = ft_i4toh_socket(ip);
	// test_getnameinfo(ip_str);
	free(ip_str);
	ft_putip_fd(ip, 1);
	ft_putstr_fd(" -> ", 1);
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
	ret += test_i4toh(0xd83ad6ae);
	ret += test_i4toh(0x4d9aed79);
	ret += test_i4toh(0xd5f50030);
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


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int convert4(struct sockaddr_in *sa, const char *name)
{
    return inet_pton(sa->sin_family = AF_INET, name, &sa->sin_addr);
}

static int convert6(struct sockaddr_in6 *sa, const char *name)
{
    return inet_pton(sa->sin6_family = AF_INET6, name, &sa->sin6_addr);
}


void	test_getnameinfo(char *ip)
{
    union {
        struct sockaddr         sa;
        struct sockaddr_in      s4;
        struct sockaddr_in6     s6;
        struct sockaddr_storage ss;
    } addr;

    if (convert4(&addr.s4, ip) != 1 && convert6(&addr.s6, ip) != 1) {
        ft_printf("%s: not a valid IP address.\n", ip);
        return ;
    }

    char node[NI_MAXHOST];
    int res = getnameinfo(&addr.sa, sizeof addr, node, sizeof node, NULL, 0, NI_NAMEREQD);
    if (res) {
        ft_printf("%s: %s\n", ip, gai_strerror(res));
        return ;
    }
	ft_printf("REAL: %s\n", node);
    return ;
}
