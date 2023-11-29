/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 00:48:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_parse(int *i_fmt, int *i_buff, \
											const char *format, va_list args)
{
	t_fmt_conf	conf;

	conf.i_fmt = i_fmt;
	(*conf.i_fmt)++;
	conf.flags = ft_printf_fmt_get_flags(i_fmt, format);
	conf.width = ft_printf_fmt_get_width(i_fmt, format);
	conf.precision = ft_printf_fmt_get_precision(i_fmt, format);
	conf.i_buff = i_buff;
	conf.fmt = format;
	ft_printf_fmt_get_type(conf, args);
}

void	ft_printf_2_parse(va_list args, const char *format)
{
	char	*ptr_buffer;
	int		i_fmt;
	int		i_buff;

	i_fmt = 0;
	i_buff = 0;
	ptr_buffer = ft_printf_buff_get();
	while (format[i_fmt] && i_buff < FT_PRINTF_BUFF_SIZE)
	{
		if (format[i_fmt] == FT_PRINTF_FMT_BEGIN)
			ft_printf_fmt_parse(&i_fmt, &i_buff, format, args);
		else
			ptr_buffer[i_buff++] = format[i_fmt++];
	}
}

t_size	ft_printf_2(const char *format, ...)
{
	va_list	args;
	char	*ptr_buffer;

	ft_printf_buff_reset();
	va_start(args, format);
	ft_printf_2_parse(args, format);
	va_end(args);
	ptr_buffer = ft_printf_buff_get();
	return (ft_putstr_fd(ptr_buffer, 1));
}
