/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoi4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:56:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_network.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	test_htoi4(char *fqdn, char *service)
{
	t_int4	retv;

	retv = ft_htoi4(fqdn, service);
	ft_printf("%s:%s -> ", fqdn, service);
	ft_putip_fd(retv, 1);
	ft_putchar_fd('\n', 1);
}

int	ci_test(void)
{
	test_htoi4("kernel.org", FT_NULL);
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

