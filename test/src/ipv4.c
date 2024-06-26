/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:10:51 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/26 01:21:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_string.h"
#include "libft_integer.h"
#include "libft_network.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	print_dcomp(t_int4 n)
{
	ft_printf("n  -> [%u]\n", n);
	ft_printf("n1 -> [%u]\n", ft_int4_dcomp(n, 3));
	ft_printf("n2 -> [%u]\n", ft_int4_dcomp(n, 2));
	ft_printf("n3 -> [%u]\n", ft_int4_dcomp(n, 1));
	ft_printf("n4 -> [%u]\n", ft_int4_dcomp(n, 0));
}

int	ci_test(void)
{
	// TODO: add more stuff
	return (0);
}

int	interactive(int ac, char **av)
{
	t_int4	ip;

	if (ac != 2)
		return (ft_perr("not enought args\n", 1));
	ip = ft_ipstr(av[1]);
	if (!ip && ft_strncmp("0.0.0.0\0", av[1], 8))
		return (ft_perr("invalid ip error\n", 2));
	print_dcomp(ip);
	ft_putip_fd(ip, 1);
	ft_putendl_fd("", 1);
	return (0);
}

int	main(int ac, char **av)
{
	if (CI_TEST)
		return (ci_test());
	else
		return (interactive(ac, av));
	return (0);
}
