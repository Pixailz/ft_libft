/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/04 22:22:30 by brda-sil         ###   ########.fr       */
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

	printf("FORMAT [NO_FORMAT]\n");
	libc = printf("LIBC: {Hello World!}\n");
	mine = ft_printf("MINE: {Hello World!}\n");
	if (libc == mine)
		printf("PASS\n\n");
	else
	{
		printf("FAIL\n\n");
		return (1);
	}
	printf("FORMAT [\x25\x25]\n");
	libc = printf("LIBC: {%%}\n");
	mine = ft_printf("MINE: {%%}\n");
	if (libc == mine)
		printf("PASS\n\n");
	else
	{
		printf("FAIL\n\n");
		return (1);
	}
	return (0);
}

int	test_print_result(t_size libc, t_size mine)
{
	int	retv;

	if (libc == mine)
	{
		printf("PASS\n\n");
		retv = 0;
	}
	else
	{
		printf("FAIL\n\n");
		retv = 1;
	}
	return (retv);
}

int	test_printf_char(char *fmt, char c)
{
	t_size	libc;
	t_size	mine;
	char	buff[FT_PRINTF_BUFF_SMALL];

	printf("FORMAT [%s]\n", fmt);
	ft_bzero(buff, FT_PRINTF_BUFF_SMALL);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, c);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf(buff, c);
	return (test_print_result(libc, mine));
}

int	test_printf_string(char *fmt, char *s)
{
	t_size	libc;
	t_size	mine;
	char	buff[FT_PRINTF_BUFF_SMALL];

	printf("FORMAT [%s]\n", fmt);
	ft_bzero(buff, FT_PRINTF_BUFF_SMALL);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, s);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf(buff, s);
	return (test_print_result(libc, mine));
}

int	test_printf_address(char *fmt, void *ptr)
{
	t_size	libc;
	t_size	mine;
	char	buff[FT_PRINTF_BUFF_SMALL];

	printf("FORMAT [%s]\n", fmt);
	ft_bzero(buff, FT_PRINTF_BUFF_SMALL);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, ptr);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf(buff, ptr);
	return (test_print_result(libc, mine));
}

int	test_printf_integer(char *fmt, int i)
{
	t_size	libc;
	t_size	mine;
	char	buff[FT_PRINTF_BUFF_SMALL];

	printf("FORMAT [%s]\n", fmt);
	ft_bzero(buff, FT_PRINTF_BUFF_SMALL);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, i);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf(buff, i);
	return (test_print_result(libc, mine));
}

int	test_printf_unsigned(char *fmt, unsigned int i)
{
	t_size	libc;
	t_size	mine;
	char	buff[FT_PRINTF_BUFF_SMALL];

	printf("FORMAT [%s]\n", fmt);
	ft_bzero(buff, FT_PRINTF_BUFF_SMALL);
	ft_strcpy(buff, "LIBC: {");
	ft_strcpy(buff + 7, fmt);
	ft_strcpy(buff + 7 + ft_strlen(fmt), "}\n");
	libc = printf(buff, i);
	ft_strncpy(buff, "MINE: {", 7);
	mine = ft_printf(buff, i);
	return (test_print_result(libc, mine));
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

int	ci_flags_padding(void)
{
	int	retv;

	retv = 0;

	retv |= test_printf_integer("%6x", 0x10);
	retv |= test_printf_integer("%#6x", 0x10);
	retv |= test_printf_integer("%06x", 0x10);
	retv |= test_printf_integer("%#06x", 0x10);
	retv |= test_printf_integer("%-6x", 0x10);
	retv |= test_printf_integer("%-#6x", 0x10);
	retv |= test_printf_integer("%-06x", 0x10);
	retv |= test_printf_integer("%-#06x", 0x10);

	// retv |= test_printf_integer("%#6x", -0x10);
	// retv |= test_printf_integer("%06x", -0x10);
	// retv |= test_printf_integer("%#06x", -0x10);
	// retv |= test_printf_integer("%-6x", -0x10);
	// retv |= test_printf_integer("%-#6x", -0x10);
	// retv |= test_printf_integer("%-06x", -0x10);
	// retv |= test_printf_integer("%-#06x", -0x10);

	retv |= test_printf_integer("%6d", 0x10);
	retv |= test_printf_integer("%06d", 0x10);
	retv |= test_printf_integer("%-6d", 0x10);
	retv |= test_printf_integer("%-06d", 0x10);

	retv |= test_printf_integer("%6d", -0x10);
	retv |= test_printf_integer("%06d", -0x10);
	retv |= test_printf_integer("%-6d", -0x10);
	retv |= test_printf_integer("%-06d", -0x10);

	retv |= test_printf_string("%6s", "abcd");
	retv |= test_printf_string("%-6s", "abcd");
	return (retv);
}

int	ci_test(void)
{
	int	retv;

	retv = 0;
	// retv |= ci_base();
	// retv |= ci_flags_padding();
	// ft_dprintf(2, "test\n");
	// ft_perr("test [%#06x]\n", 0x10);
	printf(" {%01d} \n", -9);
	ft_printf(" {%01d} \n", -9);
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
