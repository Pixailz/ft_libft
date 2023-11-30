/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/30 03:36:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"
#include <stdio.h>

#ifndef CI_TEST
# define CI_TEST FALSE
#endif

int	test_printf_base(void)
{
	t_size	libc;
	t_size	mine;

	libc = printf("LIBC: {Hello World!}\n");
	mine = ft_printf_2("MINE: {Hello World!}\n");
	if (libc == mine)
		printf("PASS [string]\n");
	else
	{
		printf("FAIL [string]\n");
		return (1);
	}
	libc = printf("LIBC: {%%}\n");
	mine = ft_printf_2("MINE: {%%}\n");
	if (libc == mine)
		printf("PASS [pourcentage]\n");
	else
	{
		printf("FAIL [pourcentage]\n");
		return (1);
	}
	return (0);
}

int	test_print_result(t_size libc, t_size mine, char *fmt)
{
	int	retv;

	if (libc == mine)
	{
		printf("PASS");
		retv = 0;
	}
	else
	{
		printf("FAIL");
		retv = 1;
	}
	printf(" [%s]\n", fmt);
	return (retv);
}

int	test_printf_char(char *fmt, char c)
{
	t_size	libc;
	t_size	mine;
	char	buff[0x100];

	ft_bzero(buff, 0x100);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, c);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf_2(buff, c);
	return (test_print_result(libc, mine, fmt));
}

int	test_printf_string(char *fmt, char *s)
{
	t_size	libc;
	t_size	mine;
	char	buff[0x100];

	ft_bzero(buff, 0x100);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, s);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf_2(buff, s);
	return (test_print_result(libc, mine, fmt));
}

int	test_printf_address(char *fmt, void *ptr)
{
	t_size	libc;
	t_size	mine;
	char	buff[0x100];

	ft_bzero(buff, 0x100);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, ptr);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf_2(buff, ptr);
	return (test_print_result(libc, mine, fmt));
}

int	test_printf_integer(char *fmt, int i)
{
	t_size	libc;
	t_size	mine;
	char	buff[0x100];

	ft_bzero(buff, 0x100);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, i);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf_2(buff, i);
	return (test_print_result(libc, mine, fmt));
}

int	test_printf_unsigned(char *fmt, unsigned int i)
{
	t_size	libc;
	t_size	mine;
	char	buff[0x100];

	ft_bzero(buff, 0x100);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, i);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf_2(buff, i);
	return (test_print_result(libc, mine, fmt));
}

int	ci_base(void)
{
	int	retv;

	retv = 0;
	retv |= test_printf_base();
	retv |= test_printf_char("%c", 'A');
	retv |= test_printf_string("%s", "This is a string.");
	retv |= test_printf_address("%p", &retv);
	retv |= test_printf_address("%p", 0);
	retv |= test_printf_integer("%i", -1234);
	retv |= test_printf_integer("%d", -1234);
	retv |= test_printf_integer("%x", 0xABCD);
	retv |= test_printf_integer("%X", 0xABCD);
	retv |= test_printf_unsigned("%u", 1234);
	return (retv);
}

int	ci_flags(void)
{
	int	retv;

	retv = 0;
	retv |= test_printf_integer("%+d", 1000);
	retv |= test_printf_integer("% d", 1000);
	retv |= test_printf_integer("% 6d", 1000);
	retv |= test_printf_integer("%+18d", 1000);
	retv |= test_printf_integer("%+-18d", 1000);
	// retv |= test_printf_integer("%#x", 0x1234);
	// retv |= test_printf_integer("%#X", 0x1234);
	// retv |= test_printf_integer("%04d", 12);
	// retv |= test_printf_integer("%04d", -12);
	// retv |= test_printf_integer("%01.3d", 0);
	return (retv);
}

int	ci_test(void)
{
	int	retv;

	retv = 0;
	retv |= ci_base();
	retv |= ci_flags();
	return (retv);
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
