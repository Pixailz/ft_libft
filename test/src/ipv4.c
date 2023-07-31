/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:10:51 by brda-sil          #+#    #+#             */
/*   Updated: 2023/07/31 20:34:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include "libft_error.h"
#include "libft_string.h"
#include "libft_integer.h"
#include "libft_network/ipv4.h"

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
		return (ft_perror("not enought args\n"));
	ip = ft_ipstr(av[1]);
	if (!ip && ft_strncmp("0.0.0.0\0", av[1], 8))
		return (ft_perror("invalid ip error\n"));
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