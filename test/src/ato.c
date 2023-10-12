/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:12:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/10/12 19:56:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_print.h"

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	test_string_u(char *nstr, char *base)
{
	int			has_overflow;
	t_uint64	n;

	n = ft_atou(nstr);
	ft_printf("atou\t\t[%s]->[%u]\n", nstr, n);
	n = ft_atou_base(nstr, base);
	ft_printf("atou_base\t[%s]->[%u]\n", nstr, n);
	n = ft_patou(nstr, &has_overflow);
	if (has_overflow)
		ft_printf("patou\t\t[%s] error\n", nstr);
	else
		ft_printf("patou\t\t[%s]->[%u]\n", nstr, n);
	n = ft_patou_base(nstr, base, &has_overflow);
	if (has_overflow)
		ft_printf("patou_base\t[%s] error\n", nstr);
	else
		ft_printf("patou_base\t[%s]->[%u]\n", nstr, n);
}

void	test_string_i(char *nstr, char *base)
{
	int		has_overflow;
	t_int64	n;

	n = ft_atoi(nstr);
	ft_printf("atoi\t\t[%s]->[%d]\n", nstr, n);
	n = ft_atoi_base(nstr, base);
	ft_printf("atoi_base\t[%s]->[%d]\n", nstr, n);
	n = ft_patoi(nstr, &has_overflow);
	if (has_overflow)
		ft_printf("patoi\t\t[%s] error\n", nstr);
	else
		ft_printf("patoi\t\t[%s]->[%d]\n", nstr, n);
	n = ft_patoi_base(nstr, base, &has_overflow);
	if (has_overflow)
		ft_printf("patoi_base\t[%s] error\n", nstr);
	else
		ft_printf("patoi_base\t[%s]->[%d]\n", nstr, n);
}

void	test_string_ll(char *nstr, char *base)
{
	int		has_overflow;
	t_int64	n;

	n = ft_atoll(nstr);
	ft_printf("atoll\t\t[%s]->[%d]\n", nstr, n);
	n = ft_atoll_base(nstr, base);
	ft_printf("atoll_base\t[%s]->[%d]\n", nstr, n);
	n = ft_patoll(nstr, &has_overflow);
	if (has_overflow)
		ft_printf("patoll\t\t[%s] error\n", nstr);
	else
		ft_printf("patoll\t\t[%s]->[%d]\n", nstr, n);
	n = ft_patoll_base(nstr, base, &has_overflow);
	if (has_overflow)
		ft_printf("patoll_base\t[%s] error\n", nstr);
	else
		ft_printf("patoll_base\t[%s]->[%d]\n", nstr, n);
}

int	test_string(char *nstr, char *base)
{
	test_string_u(nstr, base);
	test_string_i(nstr, base);
	test_string_ll(nstr, base);
	return (0);
}

void	ci_base()
{
	test_string("0xA", BUHEX);
	test_string("0xA", BUHEX);
	test_string("0x10", BUHEX);
	test_string("0xFF", BUHEX);
	test_string("-0x0A", BUHEX);
	test_string("0x", BUHEX);
	test_string("0x0a", BUHEX);

	ft_putendl_fd("", 1);

	test_string("0xa", BUHEX);
	test_string("0xa", BUHEX);
	test_string("0x10", BUHEX);
	test_string("0xff", BUHEX);
	test_string("-0x0a", BUHEX);
	test_string("0x", BUHEX);
	test_string("0x0A", BUHEX);

	ft_putendl_fd("", 1);

	test_string("1234", BDEC);
	test_string("-1234", BDEC);
	test_string("-1234.0", BDEC);
	test_string("1234.a", BDEC);

	ft_putendl_fd("", 1);

	test_string("10", BBIN);
	test_string("1011", BBIN);
	test_string("102", BBIN);
}

int	ci_test()
{
	// TODO: return value always 0

	ci_base();
	return (0);
}

int	interactive(int ac, char **av)
{
	if (ac != 3)
		return (ft_perr("args\n", 1));
	test_string(av[1], av[2]);
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
