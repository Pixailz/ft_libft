/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:22:28 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:55:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

int	test_domain(char *domain)
{
	t_int4	ip;

	ip = ft_htoi4_socket(domain);
	if (!ip)
		return (1);
	ft_printf("%-30s -> ", domain);
	ft_putip_fd(ip, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	test_not_working_domain(char *domain)
{
	t_int4	ip;

	ip = ft_htoi4_socket(domain);
	if (ip)
		return (1);
	ft_printf("%-30s -> NOT WORKING\n", domain);
	return (0);
}

int	ci_test(void)
{
	int		ret;

	ret = 0;
	ret += test_domain("www.google.com");
	ret += test_domain("google.com");
	ret += test_not_working_domain("google");		// SOA response
	ret += test_not_working_domain("google.");		// SOA response
	ret += test_not_working_domain("google..");		// SOA response
	ret += test_not_working_domain("an.unknown.domain.name");
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
