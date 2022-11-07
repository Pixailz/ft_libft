/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:52:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/07 04:38:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_integer.h>
#include <libft_print.h>

void	print_dcomp(t_int4 n)
{
	ft_printf("n  -> [%u]\n", n);
	ft_printf("n1 -> [%u]\n", ft_int4_dcomp(n, 3));
	ft_printf("n2 -> [%u]\n", ft_int4_dcomp(n, 2));
	ft_printf("n3 -> [%u]\n", ft_int4_dcomp(n, 1));
	ft_printf("n4 -> [%u]\n", ft_int4_dcomp(n, 0));
}

int	main(void)
{
	t_int1	n1;
	t_int1	n2;
	t_int1	n3;
	t_int1	n4;
	t_int4	test;

	n1 = 0;
	n2 = 1;
	n3 = 2;
	n4 = 3;
	test = ft_int4_comp(n1, n2, n3, n4);
	print_dcomp(test);
	ft_int4_inc(&test, 0);
	print_dcomp(test);
	ft_int4_dec(&test, 0);
	print_dcomp(test);
	ft_int4_chg(&test, 0, 123);
	print_dcomp(test);
	ft_int4_chg(&test, 2, 124);
	print_dcomp(test);
	return (0);
}
