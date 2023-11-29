/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 01:05:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include <stdio.h>

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

void	test_printf_base(void)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {Hello World!}\n");
	mine = ft_printf_2("MINE: {Hello World!}\n");
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

void	test_printf_pourcentage(void)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {%%}\n");
	mine = ft_printf_2("MINE: {%%}\n");
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

void	test_printf_char(char c)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {%c}\n", c);
	mine = ft_printf_2("MINE: {%c}\n", c);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

void	test_printf_string(char *s)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {%s}\n", s);
	mine = ft_printf_2("MINE: {%s}\n", s);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

void	test_printf_address(void *ptr)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {%p}\n", ptr);
	mine = ft_printf_2("MINE: {%p}\n", ptr);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

void	test_printf_integer(int i)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {%i}\n", i);
	mine = ft_printf_2("MINE: {%i}\n", i);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
	libc = printf("LIBC: {%d}\n", i);
	mine = ft_printf_2("MINE: {%d}\n", i);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

void	test_printf_unsigned(unsigned int i)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {%u}\n", i);
	mine = ft_printf_2("MINE: {%u}\n", i);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

void	test_printf_hexa(int i)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {%x}\n", i);
	mine = ft_printf_2("MINE: {%x}\n", i);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
	libc = printf("LIBC: {%X}\n", i);
	mine = ft_printf_2("MINE: {%X}\n", i);
	if (libc == mine)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

int	ci_test(void)
{
	char	dummy_var;

	dummy_var = 1;
	// test_printf_base();
	// test_printf_pourcentage();
	// test_printf_char('A');
	// test_printf_string("This is a string.");
	// test_printf_address(&dummy_var);
	// test_printf_address(0);
	// test_printf_integer(-1234);
	// test_printf_unsigned(1234);
	// test_printf_hexa(0xABCD);
	// printf("test: %+d\n", 1000);
	// ft_printf_2("test: %+d\n", 1000);
	// printf("test: % d\n", 1000);
	// ft_printf_2("test: % d\n", 1000);
	// printf("test: %#x\n", 0x1234);
	// ft_printf_2("test: %#x\n", 0x1234);
	// printf("test: %#X\n", 0x1234);
	// ft_printf_2("test: %#X\n", 0x1234);
	printf("%03d\n", -1);
	ft_printf_2("%03d\n", -1);
	// printf("%03d\n", 12);
	// ft_printf_2("%03d\n", 12);
	// printf("%01.3d\n", 0);
	// ft_printf_2("%01.3d\n", 0);
	return (0);
}

int	interactive(void)
{
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
