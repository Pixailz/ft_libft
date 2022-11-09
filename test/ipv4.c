/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:10:51 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/09 03:18:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_print.h>
#include <libft_string.h>
#include <libft_integer.h>
#include <libft_network/ipv4.h>

void	print_dcomp(t_int4 n)
{
	ft_printf("n  -> [%u]\n", n);
	ft_printf("n1 -> [%u]\n", ft_int4_dcomp(n, 3));
	ft_printf("n2 -> [%u]\n", ft_int4_dcomp(n, 2));
	ft_printf("n3 -> [%u]\n", ft_int4_dcomp(n, 1));
	ft_printf("n4 -> [%u]\n", ft_int4_dcomp(n, 0));
}

int	main(int argc, char **argv)
{
	t_int4	ip;
	t_int4	ip2;

	if (argc != 2)
		return (ft_error("not enought args", 1));
	ip = ft_ipstr(argv[1]);
	if (!ip && ft_strncmp("0.0.0.0\0", argv[1], 8))
		return (ft_error("invalid ip error", 2));
	print_dcomp(ip);
	ft_putip_fd(ip, 1);
	ft_putendl_fd("", 1);
	return (0);
}
