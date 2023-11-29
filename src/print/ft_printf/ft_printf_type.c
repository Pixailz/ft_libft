/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:49:27 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 03:14:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

#define FT_PRINTF_FMT_TYPE		"%cspdiuxX"

static void	(*g_printf_type_func[9])(t_fmt_conf conf, va_list args) = {
	ft_printf_fmt_begin,
	ft_printf_fmt_char,
	ft_printf_fmt_string,
	ft_printf_fmt_addr,
	ft_printf_fmt_integer,
	ft_printf_fmt_integer,
	ft_printf_fmt_unsigned,
	ft_printf_fmt_hex,
	ft_printf_fmt_hexa,
};

void	ft_printf_fmt_get_type(t_fmt_conf conf, va_list args)
{
	char	*ptr;
	char	type;
	int		func_lvl;

	type = conf.fmt[*conf.i_fmt];
	(*conf.i_fmt)++;
	ptr = ft_strchr(FT_PRINTF_FMT_TYPE, type);
	if (!ptr)
		return ;
	ft_bzero(conf.cur_fmt, 0x100);
	func_lvl = ptr - FT_PRINTF_FMT_TYPE;
	g_printf_type_func[func_lvl](conf, args);
}
