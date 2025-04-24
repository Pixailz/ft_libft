/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:46:32 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:43:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_setup(t_fmt_conf *conf, int *i_fmt, \
												const char *format)
{
	conf->i_fmt = i_fmt;
	(*conf->i_fmt)++;
	conf->flags = ft_printf_fmt_get_flags(i_fmt, format);
	conf->width = ft_printf_fmt_get_width(i_fmt, format);
	conf->precision = ft_printf_fmt_get_precision(i_fmt, format);
	conf->fmt = format;
}

void	ft_printf_fmt_parse(int *i_fmt, int *i_buff, \
											const char *format, va_list args)
{
	t_fmt_conf	conf = {0};
	char		*buff;
	t_size		str_len;

	ft_printf_fmt_setup(&conf, i_fmt, format);
	conf.i_buff = i_buff;
	ft_printf_fmt_get_type(&conf, args);
	buff = ft_printf_buff_get();
	if (conf.width || conf.flags & FT_PRINTF_FLAG_HASH)
		ft_printf_type_padding(&conf);
	else
	{
		if (conf.fmt_type == FMT_CHAR)
		{
			ft_strncpy(buff + *conf.i_buff, conf.cur_type, 1);
			*conf.i_buff += 1;
		}
		else
		{
			str_len = ft_strlen(conf.cur_type);
			ft_strncpy(buff + *conf.i_buff, conf.cur_type, str_len);
			*conf.i_buff += str_len;
		}
	}
}

t_size	ft_printf_parse(va_list args, const char *format)
{
	char	*ptr_buffer;
	int		i_fmt;
	int		i_buff;

	i_fmt = 0;
	i_buff = 0;
	// ft_printf_buff_reset();
	ptr_buffer = ft_printf_buff_get();
	while (format[i_fmt] && i_buff < FT_PRINTF_BUFF_BIG)
	{
		if (format[i_fmt] == FT_PRINTF_FMT_BEGIN)
			ft_printf_fmt_parse(&i_fmt, &i_buff, format, args);
		else
			ptr_buffer[i_buff++] = format[i_fmt++];
	}
	return (i_buff);
}
