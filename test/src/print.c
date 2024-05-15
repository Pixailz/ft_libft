/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:09:08 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/15 13:12:36 by brda-sil         ###   ########.fr       */
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
		printf("PASS\n");
	else
	{
		printf("FAIL\n");
		return (1);
	}
	printf("FORMAT [\x25\x25]\n");
	libc = printf("LIBC: {%%}\n");
	mine = ft_printf("MINE: {%%}\n");
	if (libc == mine)
		printf("PASS\n");
	else
	{
		printf("FAIL\n");
		return (1);
	}
	return (0);
}

char	RET_BUFF[0x200];

void	exec_piped_char(char *fmt, char c)
{
	int		pid;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid == 0) {
		close(fds[0]);
		dup2(fds[1], 1);
		ft_printf(fmt, c);
		close(1);
		close(fds[1]);
		close(fds[0]);
		exit(0);
	}
	else {
		ft_bzero(RET_BUFF, 0x200);
		close(fds[1]);
		read(fds[0], RET_BUFF, sizeof(RET_BUFF));
	}
}

int	test_print_result_char(char *buff, char c)
{
	int		retv;
	char	tmp[0x200];

	sprintf(tmp, buff, c);
	exec_piped_char(buff, c);

	printf("{%s} ", RET_BUFF);
	if (!ft_strcmp(tmp, RET_BUFF))
	{
		printf("PASS\n");
		retv = 0;
	}
	else
	{
		printf("FAIL expected %s\n", tmp);
		retv = 1;
	}
	return (retv);
}

void	exec_piped_integer(char *fmt, int i)
{
	int		pid;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid == 0) {
		close(fds[0]);
		dup2(fds[1], 1);
		ft_printf(fmt, i);
		close(1);
		close(fds[1]);
		close(fds[0]);
		exit(0);
	}
	else {
		ft_bzero(RET_BUFF, 80);
		close(fds[1]);
		read(fds[0], RET_BUFF, sizeof(RET_BUFF));
	}
}

int	test_print_result_integer(char *buff, int i)
{
	int		retv;
	char	tmp[0x200];

	sprintf(tmp, buff, i);
	exec_piped_integer(buff, i);

	printf("{%s} ", RET_BUFF);
	if (!ft_strcmp(tmp, RET_BUFF))
	{
		printf("PASS\n");
		retv = 0;
	}
	else
	{
		printf("FAIL expected %s\n", tmp);
		retv = 1;
	}
	return (retv);
}

void	exec_piped_string(char *fmt, char *s)
{
	int		pid;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid == 0) {
		close(fds[0]);
		dup2(fds[1], 1);
		ft_printf(fmt, s);
		close(1);
		close(fds[1]);
		close(fds[0]);
		exit(0);
	}
	else {
		ft_bzero(RET_BUFF, 80);
		close(fds[1]);
		read(fds[0], RET_BUFF, sizeof(RET_BUFF));
	}
}

int	test_print_result_string(char *buff, char *s)
{
	int		retv;
	char	tmp[0x200];

	sprintf(tmp, buff, s);
	exec_piped_string(buff, s);

	printf("{%s} ", RET_BUFF);
	if (!ft_strcmp(tmp, RET_BUFF))
	{
		printf("PASS\n");
		retv = 0;
	}
	else
	{
		printf("FAIL expected %s\n", tmp);
		retv = 1;
	}
	return (retv);
}

void	exec_piped_ptr(char *fmt, void *ptr)
{
	int		pid;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid == 0) {
		close(fds[0]);
		dup2(fds[1], 1);
		ft_printf(fmt, ptr);
		close(1);
		close(fds[1]);
		close(fds[0]);
		exit(0);
	}
	else {
		ft_bzero(RET_BUFF, 80);
		close(fds[1]);
		read(fds[0], RET_BUFF, sizeof(RET_BUFF));
	}
}

int	test_print_result_ptr(char *buff, void *ptr)
{
	int		retv;
	char	tmp[0x200];

	sprintf(tmp, buff, ptr);
	exec_piped_ptr(buff, ptr);

	printf("{%s} ", RET_BUFF);
	if (!ft_strcmp(tmp, RET_BUFF))
	{
		printf("PASS\n");
		retv = 0;
	}
	else
	{
		printf("FAIL expected %s\n", tmp);
		retv = 1;
	}
	return (retv);
}

void	exec_piped_unsigned(char *fmt, unsigned int i)
{
	int		pid;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid == 0) {
		close(fds[0]);
		dup2(fds[1], 1);
		ft_printf(fmt, i);
		close(1);
		close(fds[1]);
		close(fds[0]);
		exit(0);
	}
	else {
		ft_bzero(RET_BUFF, 80);
		close(fds[1]);
		read(fds[0], RET_BUFF, sizeof(RET_BUFF));
	}
}

int	test_print_result_unsigned(char *buff, unsigned int i)
{
	int		retv;
	char	tmp[0x200];

	sprintf(tmp, buff, i);
	exec_piped_unsigned(buff, i);

	printf("{%s} ", RET_BUFF);
	if (!ft_strcmp(tmp, RET_BUFF))
	{
		printf("PASS\n");
		retv = 0;
	}
	else
	{
		printf("FAIL expected %s\n", tmp);
		retv = 1;
	}
	return (retv);
}

int	test_printf_char(char *fmt, char c)
{
	printf("FORMAT [%s] VALUE [%c] ", fmt, c);
	return (test_print_result_char(fmt, c));
}

int	test_printf_string(char *fmt, char *s)
{
	printf("FORMAT [%s] VALUE [%s] ", fmt, s);
	return (test_print_result_string(fmt, s));
}

int	test_printf_address(char *fmt, void *ptr)
{
	printf("FORMAT [%s] VALUE [%p] ", fmt, ptr);
	return (test_print_result_ptr(fmt, ptr));
}

int	test_printf_integer(char *fmt, int i)
{
	printf("FORMAT [%s] VALUE [%i] ", fmt, i);
	return (test_print_result_integer(fmt, i));
}

int	test_printf_unsigned(char *fmt, unsigned int i)
{
	printf("FORMAT [%s] VALUE [%u] ", fmt, i);
	return (test_print_result_unsigned(fmt, i));
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

	retv |= test_printf_integer("%#6x", -0x10);
	retv |= test_printf_integer("%06x", -0x10);
	retv |= test_printf_integer("%#06x", -0x10);
	retv |= test_printf_integer("%-6x", -0x10);
	retv |= test_printf_integer("%-#6x", -0x10);
	retv |= test_printf_integer("%-06x", -0x10);
	retv |= test_printf_integer("%-#06x", -0x10);

	retv |= test_printf_integer("%6d", 0x10);
	retv |= test_printf_integer("%06d", 0x10);
	retv |= test_printf_integer("%-6d", 0x10);
	retv |= test_printf_integer("%-06d", 0x10);

	retv |= test_printf_integer("%6d", -0x10);
	retv |= test_printf_integer("%06d", -0x10);
	retv |= test_printf_integer("%-6d", -0x10);
	retv |= test_printf_integer("%-06d", -0x10);
	retv |= test_printf_integer("%01d", -9);

	retv |= test_printf_string("%6s", "abcd");
	retv |= test_printf_string("%-6s", "abcd");
	return (retv);
}

int	ci_test(void)
{
	int	retv;

	retv = 0;
	retv |= ci_base();
	retv |= ci_flags_padding();
	// ft_dprintf(2, "test\n");
	// ft_perr("test [%#06x]\n", 0x10);
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
