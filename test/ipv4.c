/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:10:51 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/14 05:56:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_dcomp(t_int4 n)
{
	ft_printf("n  -> [%d]\n", n);
	ft_printf("n1 -> [%u]\n", ft_int4_dcomp(n, 0));
	ft_printf("n2 -> [%u]\n", ft_int4_dcomp(n, 1));
	ft_printf("n3 -> [%u]\n", ft_int4_dcomp(n, 2));
	ft_printf("n4 -> [%u]\n\n", ft_int4_dcomp(n, 3));
}

int	main(int argc, char **argv)
{
	t_int4	ip;

	if (argc != 2)
		return (ft_error("not enought args", 1));
	ip = ft_ipstr(argv[1]);
	if (!ip)
		return (ft_error("invalid ip error", 2));
	print_dcomp(ip);
	return (0);
}
