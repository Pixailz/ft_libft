/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:32:03 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 16:46:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

static int	ft_put_addr(va_list args)
{
	long long	addr;

	addr = va_arg(args, unsigned long long);
	if (!addr)
		return (ft_putstr_fd("(nil)", 1));
	return (ft_putstr_fd("0x", 1) + \
					ft_putstr_fd(ft_itoa_base(addr, "0123456789abcdef"), 1));
}

static int	ft_sel_params(va_list args, char param_type)
{
	if (param_type == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (param_type == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (param_type == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (param_type == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (param_type == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	else if (param_type == 'p')
		return (ft_put_addr(args));
	else if (param_type == 'x')
		return (ft_putstr_fd(ft_itoa_base(va_arg(args, int), \
													"0123456789abcdef"), 1));
	else if (param_type == 'X')
		return (ft_putstr_fd(ft_itoa_base(va_arg(args, int), \
													"0123456789ABCDEF"), 1));
	else if (param_type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

static int	ft_checkparams(char c)
{
	char	*t;

	t = FT_PRINTF_PARAMS_LIST;
	while (*t)
		if (c == *t++)
			return (1);
	return (0);
}

int	ft_printf_parse(va_list args, const char *format)
{
	int	size;

	size = 0;
	while (*format)
	{
		if (*format == '%' && ft_checkparams(*(format + 1)))
			size += ft_sel_params(args, *(format++ + 1));
		else
			size += ft_putchar_fd(*format, 1);
		format++;
	}
	return (size);
}

size_t	ft_printf(const char *format, ...)
{
	size_t	size;
	va_list	args;

	size = 0;
	va_start(args, format);
	size = ft_printf_parse(args, format);
	va_end(args);
	return (size);
}
