/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:28:01 by brda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 01:01:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_type_padding_addr_short(t_fmt_conf *conf, char *buff, \
											t_size str_len)
{
	if (conf->flags & FT_PRINTF_FLAG_MINUS)
		ft_strncpy(buff + *conf->i_buff, conf->cur_type, str_len);
	else
		ft_strncpy(buff + *conf->i_buff + conf->width - str_len, \
												conf->cur_type, str_len);
	(*conf->i_buff) += conf->width;
}

void	ft_printf_type_padding_addr(t_fmt_conf *conf)
{
	t_size	begin;
	int		to_pad;
	t_size	str_len;
	char	*buff;

	buff = ft_printf_buff_get();
	str_len = ft_strlen(conf->cur_type);
	to_pad = conf->width - str_len;
	begin = *conf->i_buff;
	if (conf->flags & FT_PRINTF_FLAG_MINUS)
		begin += str_len;
	while (to_pad-- > 0)
		buff[begin++] = ' ';
	if (str_len > conf->width)
	{
		if (conf->flags & FT_PRINTF_FLAG_MINUS)
			ft_strncpy(buff + *conf->i_buff, conf->cur_type, str_len);
		else
			ft_strncpy(buff + *conf->i_buff, conf->cur_type, str_len);
		(*conf->i_buff) += str_len;
	}
	else
		ft_printf_type_padding_addr_short(conf, buff, str_len);
}
