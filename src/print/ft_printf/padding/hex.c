/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:29:05 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/15 13:15:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_padding_hex_hashtag(t_fmt_conf *conf, \
													t_size str_len)
{
	char	*buff;

	buff = ft_printf_buff_get();
	if (conf->flags & FT_PRINTF_FLAG_HASH)
	{
		if (conf->flags & (FT_PRINTF_FLAG_MINUS | FT_PRINTF_FLAG_ZERO))
		{
			if (conf->fmt_type == FMT_HEX)
				ft_strncpy(buff + *conf->i_buff, "0x", 2);
			else
				ft_strncpy(buff + *conf->i_buff, "0X", 2);
			*conf->i_buff += 2;
			conf->width -= 2;
		}
		else
		{
			char	*tmp;

			tmp = ft_strdup(conf->cur_type);
			ft_memcpy(conf->cur_type + 2, tmp, str_len);
			free(tmp);
			if (conf->fmt_type == FMT_HEX)
				ft_memcpy(conf->cur_type, "0x", 2);
			else
				ft_memcpy(conf->cur_type, "0X", 2);
		}
	}
}

void	ft_printf_type_padding_hex_post(t_fmt_conf *conf, char sign, \
																t_size str_len)
{
	char	*buff;

	buff = ft_printf_buff_get();
	if (sign && !(conf->flags & FT_PRINTF_FLAG_MINUS))
	{
		if (conf->flags & FT_PRINTF_FLAG_ZERO)
			buff[(*conf->i_buff)++] = sign;
		else
			buff[(*conf->i_buff)++ + conf->width - str_len - 1] = sign;
	}
	if (conf->width < str_len)
		conf->width = str_len;
	if (conf->flags & FT_PRINTF_FLAG_MINUS)
		ft_strncpy(buff + *conf->i_buff, conf->cur_type, str_len + (sign != 0));
	else
		ft_strncpy(buff + *conf->i_buff + conf->width - str_len - (sign != 0), \
										conf->cur_type + (sign != 0), str_len);
	if (str_len >= conf->width)
		(*conf->i_buff) += str_len + (sign != 0);
	else
		(*conf->i_buff) += conf->width;
}

void	ft_printf_type_padding_hex_pad(t_fmt_conf *conf, t_size begin, \
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
	while (to_pad > 0)
	{
		buff[begin++] = pad_str;
		to_pad--;
	}
}

void	ft_printf_type_padding_hex(t_fmt_conf *conf)
{
	t_size	begin;
	int		to_pad;
	t_size	str_len;
	char	sign;

	sign = ft_printf_type_padding_remove_sign(conf->cur_type);
	str_len = ft_strlen(conf->cur_type) - (sign != 0);
	to_pad = conf->width - str_len;
	ft_printf_type_padding_hex_hashtag(conf, str_len);
	str_len = ft_strlen(conf->cur_type) - (sign != 0);
	to_pad = conf->width - str_len;
	begin = *conf->i_buff;
	if (conf->flags & FT_PRINTF_FLAG_MINUS)
		begin += str_len;
	ft_printf_type_padding_hex_pad(conf, begin, to_pad);
	ft_printf_type_padding_hex_post(conf, sign, str_len);
}
