/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:15:45 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/03 15:56:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

char	ft_printf_type_padding_remove_sign(char *str)
{
	char	retv;

	retv = 0;
	if (str[0] == '-')
		retv = '-';
	return (retv);
}

void	ft_printf_type_padding(t_fmt_conf *conf)
{
	if (conf->fmt_type == FMT_HEX || conf->fmt_type == FMT_HEXA)
		ft_printf_type_padding_hex(conf);
	else if (conf->fmt_type == FMT_DIGI || conf->fmt_type == FMT_INTE)
		ft_printf_type_padding_integer(conf);
	else if (conf->fmt_type == FMT_STRI)
		ft_printf_type_padding_string(conf);
}
