/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/30 03:31:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_integer_sign(t_fmt_conf *conf)
{
	if (conf->flags & FT_PRINTF_FLAG_PLUS)
		ft_strncpy(conf->cur_fmt, "+", 1);
	else if (conf->flags & FT_PRINTF_FLAG_SPACE)
		ft_strncpy(conf->cur_fmt, " ", 1);
}

void	ft_printf_fmt_integer_padding(t_fmt_conf *conf, t_size str_len)
{
	int		pad_char;
	char	sign;
	int		i;

	if (conf->flags & FT_PRINTF_FLAG_ZERO)
		pad_char = '0';
	else
		pad_char = ' ';
	sign = conf->cur_fmt[0];
	i = 0;
	str_len += sign != 0;
	while (str_len < conf->width)
	{
		conf->cur_fmt[i] = pad_char;
		str_len++;
		i++;
	}
	conf->cur_fmt[ft_strlen(conf->cur_fmt)] = sign;
}

void	ft_printf_fmt_integer(t_fmt_conf conf, va_list args)
{
	char	*buff;
	int		i;
	char	*i_str;
	t_size	str_len;

	buff = ft_printf_buff_get();
	i = va_arg(args, int);
	i_str = ft_itoa_base(i, "0123456789");
	str_len = ft_strlen(i_str);
	if (i > 0)
		ft_printf_fmt_integer_sign(&conf);
	if (conf.width)
		ft_printf_fmt_integer_padding(&conf, str_len);
	ft_strncpy(conf.cur_fmt + ft_strlen(conf.cur_fmt), i_str, str_len);
	str_len = ft_strlen(conf.cur_fmt);
	ft_strncpy(buff + *conf.i_buff, conf.cur_fmt, str_len);
	free(i_str);
	*conf.i_buff += str_len;
}
