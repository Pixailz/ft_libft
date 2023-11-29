/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:20:11 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 13:22:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

void	ft_printf_fmt_integer_sign(t_fmt_conf conf)
{
	if (conf.flags & FT_PRINTF_FLAG_PLUS)
		ft_strncpy(conf.cur_fmt, "+", 1);
	else if (conf.flags & FT_PRINTF_FLAG_SPACE)
		ft_strncpy(conf.cur_fmt, " ", 1);
}

void	ft_printf_fmt_integer(t_fmt_conf conf, va_list args)
{
	char	*buff;
	int		i;
	char	*i_str;
	t_size	i_str_len;

	buff = ft_printf_buff_get();
	i = va_arg(args, int);
	i_str = ft_itoa_base(i, "0123456789");
	i_str_len = ft_strlen(i_str);
	if (i > 0)
		ft_printf_fmt_integer_sign(conf);
	if (conf.flags & FT_PRINTF_FLAG_ZERO)
		i = '0';
	else
		i = ' ';
	while (i_str_len < conf.width)
	{
		buff[(*conf.i_buff)++ + ft_strlen(conf.cur_fmt)] = i;
		i_str_len++;
	}
	ft_strncpy(conf.cur_fmt + ft_strlen(conf.cur_fmt), i_str, i_str_len);
	free(i_str);
	*conf.i_buff += i_str_len;
}
