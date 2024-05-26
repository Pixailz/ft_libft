/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hton.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

#include <arpa/inet.h>
#include <stdio.h>

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	test_htons(t_uint64 n)
{
	ft_printf("0x%lx|real  : 0x%x\n", n, htons(n));
	ft_printf("0x%lx|libft : 0x%x\n", n, ft_htons(n));
}

void	test_htonl(t_uint64 n)
{
	printf("0x%lx|real  : 0x%x\n", n, htonl(n));
	printf("0x%lx|libft : 0x%x\n", n, ft_htonl(n));
}

void	test_ntohs(t_uint64 n)
{
	printf("0x%lx|real  : 0x%x\n", n, ntohs(n));
	printf("0x%lx|libft : 0x%x\n", n, ft_ntohs(n));
}

void	test_ntohl(t_uint64 n)
{
	printf("0x%lx|real  : 0x%x\n", n, ntohl(n));
	printf("0x%lx|libft : 0x%x\n", n, ft_ntohl(n));
}

int	ci_test(void)
{
	test_htons(0x1234);
	test_htons(0x12345678);
	printf("\n");
	test_ntohs(0x1234);
	test_ntohs(0x12345678);
	printf("\n");
	test_htonl(0x12345678);
	test_htonl(0x123456789ABCDEF0);
	printf("\n");
	test_ntohl(0x12345678);
	test_ntohl(0x123456789ABCDEF0);
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
