/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:28:37 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/15 10:56:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_padding_integer_post(t_fmt_conf *conf, char sign, \
											char *buff)
{
	t_size	str_len;

	str_len = ft_strlen(conf->cur_type) - (sign != 0);
	if (sign && !(conf->flags & FT_PRINTF_FLAG_MINUS))
	{
		if (conf->flags & FT_PRINTF_FLAG_ZERO)
			buff[*conf->i_buff] = sign;
		else
			buff[*conf->i_buff + conf->width - str_len - 1] = sign;
	}
	if (conf->width < str_len)
		conf->width = str_len;
	if (conf->flags & FT_PRINTF_FLAG_MINUS)
		ft_strncpy(buff + *conf->i_buff, conf->cur_type, str_len + (sign != 0));
	else
	{
		int	pos;

		pos = *conf->i_buff + conf->width - str_len;
		if (conf->width == str_len && sign != 0)
			pos++;

		if (conf->width >= str_len)
			ft_strncpy(buff + pos, conf->cur_type + (sign != 0), str_len);
		else
			ft_strncpy(buff + *conf->i_buff, \
										conf->cur_type + (sign != 0), str_len);
	}
	if (str_len >= conf->width)
		(*conf->i_buff) += str_len + (sign != 0);
	else
		(*conf->i_buff) += conf->width;
}

void	ft_printf_type_padding_integer_pad(t_fmt_conf *conf, t_size begin, \
																	int to_pad)
{
	char	pad_str;
	char	*buff;

	buff = ft_printf_buff_get();
	if (conf->flags & FT_PRINTF_FLAG_ZERO && \
										!(conf->flags & FT_PRINTF_FLAG_MINUS))
		pad_str = '0';
	else
		pad_str = ' ';
	while (to_pad >= 0)
	{
		buff[begin++] = pad_str;
		to_pad--;
	}
}

void	ft_printf_type_padding_integer(t_fmt_conf *conf)
{
	t_size	begin;
	int		to_pad;
	char	sign;
	t_size	str_len;
	char	*buff;

	sign = ft_printf_type_padding_remove_sign(conf->cur_type);
	str_len = ft_strlen(conf->cur_type) - (sign != 0);
	to_pad = conf->width - str_len;
	begin = *conf->i_buff;
	if (conf->flags & FT_PRINTF_FLAG_MINUS)
		begin += str_len;
	ft_printf_type_padding_integer_pad(conf, begin, to_pad);
	buff = ft_printf_buff_get();
	ft_printf_type_padding_integer_post(conf, sign, buff);
}
