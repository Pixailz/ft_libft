/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:49:27 by brda-sil          #+#    #+#             */
/*   Updated: 2023/12/01 11:15:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

static void	(*g_printf_type_func[9])(t_fmt_conf *conf, va_list args) = {
	ft_printf_type_begin,
	ft_printf_type_char,
	ft_printf_type_string,
	ft_printf_type_addr,
	ft_printf_type_integer,
	ft_printf_type_integer,
	ft_printf_type_unsigned,
	ft_printf_type_hex,
	ft_printf_type_hexa,
};

void	ft_printf_type_sign(t_fmt_conf *conf)
{
	if (conf->flags & FT_PRINTF_FLAG_PLUS)
		ft_strncpy(conf->cur_type, "+", 1);
	else if (conf->flags & FT_PRINTF_FLAG_SPACE)
		ft_strncpy(conf->cur_type, " ", 1);
}

void	ft_printf_fmt_get_type(t_fmt_conf *conf, va_list args)
{
	char	*ptr;
	char	type;
	int		func_lvl;

	type = conf->fmt[*conf->i_fmt];
	(*conf->i_fmt)++;
	ptr = ft_strchr(FT_PRINTF_FMT_TYPE, type);
	if (!ptr)
		return ;
	ft_bzero(conf->cur_type, FT_PRINTF_BUFF_SMALL);
	func_lvl = ptr - FT_PRINTF_FMT_TYPE;
	g_printf_type_func[func_lvl](conf, args);
	conf->fmt_type = func_lvl;
}
