/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:36:06 by brda-sil          #+#    #+#             */
/*   Updated: 2023/11/28 22:23:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

#define FT_PRINTF_FLAGS			"-+ #0"

static void	(*g_printf_flag_func[5])(char type, t_bin *flags) = {
	ft_printf_flag_minus,
	ft_printf_flag_plus,
	ft_printf_flag_space,
	ft_printf_flag_hash,
	ft_printf_flag_zero,
};

t_bin	ft_printf_fmt_get_flags(int *i, const char *format)
{
	char	*ptr;
	char	type;
	int		func_lvl;
	t_bin	flag;

	flag = 0;
	type = format[*i];
	ptr = ft_strchr(FT_PRINTF_FLAGS, type);
	while (ptr)
	{
		(*i)++;
		func_lvl = ptr - FT_PRINTF_FLAGS;
		g_printf_flag_func[func_lvl](type, &flag);
		type = format[*i];
		ptr = ft_strchr(FT_PRINTF_FLAGS, type);
	}
	return (flag);
}
