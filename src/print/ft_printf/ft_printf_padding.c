/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:15:45 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 11:38:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

/*
	int		pad_char;
	char	sign;
	int		i;

	if (conf->flags & FT_PRINTF_FLAG_ZERO)
		pad_char = '0';
	else
		pad_char = ' ';
	sign = conf->cur_type[0];
	i = 0;
	str_len += sign != 0;
	while (str_len < conf->width)
	{
		conf->cur_type[i] = pad_char;
		str_len++;
		i++;
	}
	conf->cur_type[ft_strlen(conf->cur_type)] = sign;

0x10
%-6x	'10    '
%-#6x	'0x10  '
%-06x	'10    '
%-#06x	'0x10  '
%6x		'    10'
%#6x	'  0x10'
%06x	'000010'
%#06x	'0x0010'
*/

void	ft_printf_type_padding_hex(t_fmt_conf *conf)
{
	(void)conf;
}

void	ft_printf_type_padding(t_fmt_conf *conf)
{
	if (conf->fmt_type & (FMT_HEX | FMT_HEXA))
		ft_printf_type_padding_hex(conf);
}
